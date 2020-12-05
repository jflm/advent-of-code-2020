#include <iostream>

int main(void) {

    int min = 1000000;
    int count = 0;
    long long sum = 0;

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

        count++;
        min = id < min ? id : min;
        sum += id;
    }

    sum -= (count * min);
    long long n = count * (count + 1) / 2;
    int missing = n - sum + min;

    std::cout << "missing: " << missing << std::endl;

}
