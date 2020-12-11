#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <set>

struct operation {
    std::string op;
    int arg;
};

int simulate_program(std::vector<operation> ops, bool should_flip);

int main(void) {

    std::vector<operation> ops;

    char op[4];
    int arg;
    while(scanf("%s %d", op, &arg) > 0) {
        operation o;
        o.op = op;
        o.arg = arg;
        ops.push_back(o);
    }

    int out = simulate_program(ops, true);
    if (out != -1) {
        std::cout << "value of acc is " << out << std::endl;
    }

}

// return the value in the accumulator once the program terminates 'naturally'
// otherwise return -1 if the program enters an infinite loop
// for each jmp or nop instruction, simulate the behaviour of the program if the
// operation were swapped
int simulate_program(std::vector<operation> ops, bool should_flip) {

    std::set<int> visited;
    int acc = 0;

    for(int i = 0; i < ops.size() + 1; i++) {

        if (i >= ops.size()) {
            return acc;
        }

        if (visited.find(i) != visited.end()) {
            return -1;
        }

        visited.insert(i);
        operation o = ops.at(i);

        if (o.op.compare("acc") == 0) {

            acc += o.arg;

        } else if (o.op.compare("jmp") == 0) {

            std::vector<operation> cp = ops;
            cp[i].op = "nop";

            if (should_flip) {
                int simulation = simulate_program(cp, false);
                if (simulation != -1) {
                    return simulation;
                }
            }

            if (o.arg != 0 ) {
                i += o.arg - 1;
            }

        } else { // op = "nop"

            if (o.arg != 0 && should_flip) {
                std::vector <operation> cp = ops;
                cp[i].op = "jmp";

                int simulation = simulate_program(cp, false);
                if (simulation != -1) {
                    return simulation;
                }
            }

        }

    }

    return -1;
}
