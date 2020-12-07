#include <iostream>
#include <string>
#include <vector>

int main(void) {

    std::string person;
    std::vector<char> group_answers;

    int count = 0;
    bool skip = false;

    while(std::getline(std::cin, person, '\n')) {
        if (person.empty()) { // end of the previous group
            skip = false;
            count += group_answers.size();
            group_answers.clear();
        }

        if (skip) { continue; }

        // for the first person, put all their answers into a vector
        // for subsequent people, remove any answers in the vector which
        // do not apply for this person
        if (group_answers.empty()) {
            for (char c : person) {
                group_answers.push_back(c);
            }
        } else {
            for (int i = 0; i < group_answers.size(); i++) {
                if (person.find(group_answers.at(i)) == std::string::npos) {
                    group_answers.erase(group_answers.begin() + i);
                    i--; // bit gross but hey ho, should work
                }
            }
            if (group_answers.empty()) {
                skip = true;
            }
        }

    }

    count += group_answers.size(); // get the final group

    std::cout << count << std::endl;

}
