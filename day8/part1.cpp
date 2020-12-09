#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <set>

struct operation {
    std::string op;
    int arg;
};

int main(void) {

    // can't see how we can avoid reading the whole thing into memory
    std::vector<operation> ops;
    std::set<int> visited;
    int acc = 0;

    char op[4];
    int arg;
    while(scanf("%s %d", op, &arg) > 0) {
        operation o;
        o.op = op;
        o.arg = arg;
        ops.push_back(o);
    }

    for (int i = 0; i < ops.size(); i++) {
        operation o = ops.at(i);

        if (visited.find(i) != visited.end()) {
            std::cout << "value of acc is " << acc << std::endl;
            return 0;
        }
        visited.insert(i);

        if (o.op.compare("acc") == 0) {
            acc += o.arg;
        } else if (o.op.compare("jmp") == 0) {
            i += o.arg - 1;
        }
    }

}