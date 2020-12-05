#include <iostream>
#include <vector>

int main(void) {

    // suspect there is a more efficient way of doing this
    std::vector<int> ids;

    char seat[11];
    while(std::cin >> seat) {

        int row = 0;
        int col = 0;

        for (int i = 0; i < 7; i++) {
            char operation = seat[i];
            row <<= 1;
            row += operation == 'B';
        }

        for (int i = 7; i < 10; i++) {
            char operation = seat[i];
            col <<= 1;
            col += operation == 'R';
        }

        int id = row * 8 + col;

        ids.push_back(id);
    }

    sort(ids.begin(), ids.end());

    int prev = *ids.begin() - 1;
    for (auto i : ids) {
        if (i != prev + 1) {
            std::cout << "missing: " << i - 1 << std::endl;
        }
        prev = i;
    }

}
