#include <iostream>

int main(void) {

    int highest = 0;

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

        if (id > highest) {
            highest = id;
        }
    }

    std::cout << highest << std::endl;

}
