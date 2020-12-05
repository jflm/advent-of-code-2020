#include <iostream>
#include <string>
#include <regex>
#include <map>

bool valid_int(std::string s, int from, int to);
bool valid_by_regex(std::string s, std::regex regex);
bool valid_height(std::string s);

static const std::regex FIELD_REGEX("[a-z]{3}:[^\\s]*");
static const std::map<std::string, std::function<bool (std::string)>> REQUIRED_FIELDS = {
        {"byr", [](std::string s) {
            return valid_int(s, 1920, 2002);
        }},
        {"iyr", [](std::string s) {
            return valid_int(s, 2010, 2020);
        }},
        {"eyr", [](std::string s) {
            return valid_int(s, 2020, 2030);
        }},
        {"hgt", [](std::string s) {
            return valid_height(s);
        }},
        {"hcl", [](std::string s) {
            return valid_by_regex(s, std::regex("^#[0-9a-f]{6}$"));
        }},
        {"ecl", [](std::string s) {
            return valid_by_regex(s, std::regex("^(amb|blu|brn|gry|grn|hzl|oth)$"));
        }},
        {"pid", [](std::string s) {
            return valid_by_regex(s, std::regex("^[0-9]{9}$"));
        }}
};

bool dataset_is_valid(std::string dataset) {
    auto begin = std::sregex_iterator(dataset.begin(), dataset.end(), FIELD_REGEX);
    auto end = std::sregex_iterator();

    int valid_field_count = 0;

    for (std::sregex_iterator it = begin; it != end; it++) {
        std::string item = (*it).str();
        std::string key = item.substr(0, 3);
        std::string value = item.substr(4);

        for (auto field : REQUIRED_FIELDS) {
            if ((field.first).compare(key) == 0) {
                valid_field_count += field.second(value);
            }
        }
    }

    return valid_field_count == 7;
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

bool valid_int(std::string s, int from, int to) {
    int i = std::stoi(s);
    return i >= from && i <= to;
}

bool valid_by_regex(std::string s, std::regex regex) {
    return std::regex_match(s, regex);
}

bool valid_height(std::string s) {
    std::string unit = s.substr(s.size() - 2, 2);
    std::string value = s.substr(0, s.size() - 2);

    if (unit.compare("cm") == 0) {
        return valid_int(value, 150, 193);
    } else if (unit.compare("in") == 0) {
        return valid_int(value, 59, 76);
    }

    return false;
}
