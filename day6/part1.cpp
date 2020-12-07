#include <iostream>
#include <string>
#include <set>

int main(void) {

    std::string person;
    std::set<char> group_answers;

    int count = 0;

    while(std::getline(std::cin, person, '\n')) {
        if (person.empty()) { // end of the previous group
            count += group_answers.size();
            group_answers.clear();
        }
        const char *answers = person.c_str();
        for (int i = 0; i < person.size(); i++) {
            group_answers.insert(answers[i]);
        }
    }

    count += group_answers.size(); // get the final group

    std::cout << count << std::endl;

}
