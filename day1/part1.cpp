#include <iostream>
#include <unordered_map>

int main(void) {

    // complements holds the required number to make 2020 for each element seen so far
    // so if we find a number in the complements list, we know that we can make 2020 with
    // the element that we saw previously
    std::unordered_map<int, int> complements;

    int n;
    while (std::cin >> n) {
        std::unordered_map<int, int>::iterator it = complements.find(n);
        if (it != complements.end()) {
            std::cout << it->first << " + " << it->second << " = 2020. Product: " << it->first * it->second << std::endl;
            return 0;
        }
        complements[2020 - n] = n;
    }

}
