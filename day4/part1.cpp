#include <iostream>
#include <string>
#include <vector>
#include <regex>

static const std::regex FIELD_REGEX("[a-z]{3}:");
static const std::vector<std::string> REQUIRED_FIELDS = {
        "byr",
        "iyr",
        "eyr",
        "hgt",
        "hcl",
        "ecl",
        "pid"
};

bool dataset_is_valid(std::string dataset) {
    auto begin = std::sregex_iterator(dataset.begin(), dataset.end(), FIELD_REGEX);
    auto end = std::sregex_iterator();

    int field_count = 0;

    for (std::sregex_iterator it = begin; it != end; it++) {
        std::string item = (*it).str();

        // not sure whether it is best to iterate over the fields first or the found items...
        for (auto field : REQUIRED_FIELDS) {
            if ((field + ":").compare(item) == 0) {
                field_count++;
            }
        }
    }

    return field_count == 7;
}

int main(void) {

    std::string line;
    std::string dataset;

    int c_valid = 0;

    while (std::getline(std::cin, line, '\n')) {
        if (line.empty()) { // end of the previous dataset
            c_valid += dataset_is_valid(dataset);
            dataset = "";
        }
        dataset += ' ' + line;
    }

    c_valid += dataset_is_valid(dataset); // final dataset

    std::cout << c_valid << " record(s) were valid" << std::endl;

}
