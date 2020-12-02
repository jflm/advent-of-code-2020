#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> find_pairs(std::vector<int> numbers, int target) {
    // complements holds the required number to make 2020 for each element seen so far
    // so if we find a number in the complements list, we know that we can make 2020 with
    // the element that we saw previously
    std::unordered_map<int, int> complements;

    for (auto n : numbers) {
        std::unordered_map<int, int>::iterator it = complements.find(n);
        if (it != complements.end()) {
            return { it->first, it->second };
        }
        complements[target - n] = n;
    }

    return {};
}

std::vector<int> find_combinations(std::vector<int> numbers, int target, int n_operands) {
    // kind of a basic recursive implementation, although still seems quite fast.
    // probably something we could do with DP to improve performance

    if (n_operands == 2) {
        return find_pairs(numbers, target);
    }

    for (auto n : numbers) {
        // find me a set of size n_operands - 1 from the remaining numbers that adds up to target minus this number
        std::vector<int> sub(&numbers[1], &numbers[numbers.size() - 1]);
        std::vector<int> found = find_combinations(sub, target - n, n_operands - 1);
        if (!found.empty()) {
            return { n, found[0], found[1] }; // grim way to combine vectors but hey ho
        }
    }

    return {};
}

int main(void) {

    std::vector<int> numbers;
    int n;
    while (std::cin >> n) {
        numbers.push_back(n);
    }

    std::vector<int> terms = find_combinations(numbers, 2020, 3);
    if (!terms.empty()) {
        std::cout << terms[0] << " + " << terms[1] << " + " << terms[2] << " = 2020. Product: " << terms[0] * terms[1] * terms[2] << std::endl;
    }

}
