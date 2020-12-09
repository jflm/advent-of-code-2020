#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

struct link {
    int from;
    int to;
    int n;
};

int get_contained(std::string name, std::vector<std::string> nodes, std::vector<link> links);

int main(void) {

    std::vector<std::string> nodes;
    std::vector<link> links;

    std::string rule;
    while(std::getline(std::cin, rule, '\n')) {

        int n = rule.find(" bags");
        std::string bag_name = rule.substr(0, n);
        rule.erase(0, n + 14); // strip off ' bags contain '

        int idx_a;
        auto f = find(nodes.begin(), nodes.end(), bag_name);
        if (f != nodes.end()) {
            idx_a = f - nodes.begin();
        } else {
            idx_a = nodes.size();
            nodes.push_back(bag_name);
        }

        size_t pos = 0;
        while((pos = rule.find_first_of(",.")) != std::string::npos) {
            int n = 0;
            std::string n_s;
            if ((n_s = rule.substr(0, 1)) != "n") {
                n = std::stoi(n_s);
            }

            std::string sub_bag_name = rule.substr(2, rule.find(" bag") - 2);

            if (sub_bag_name.compare(" other") != 0) {

                int idx_b;

                auto it = find(nodes.begin(), nodes.end(), sub_bag_name);
                if (it != nodes.end()) {
                    idx_b = it - nodes.begin();
                } else {
                    idx_b = nodes.size();
                    nodes.push_back(sub_bag_name);
                }

                link l;
                l.from = idx_a;
                l.to = idx_b;
                l.n = n;
                links.push_back(l);
            }

            rule.erase(0, pos + 2);
        }

    }

    int c = get_contained("shiny gold", nodes, links);

    std::cout << c << std::endl;
}

int get_contained(std::string name, std::vector<std::string> nodes, std::vector<link> links) {
    int count = 0;
    int idx = find(nodes.begin(), nodes.end(), name) - nodes.begin();
    for (auto l : links) {
        if (l.from == idx) {
            count += l.n;
            count += (l.n * get_contained(nodes.at(l.to), nodes, links));
        }
    }
    return count;
}
