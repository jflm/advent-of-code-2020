#include <stdio.h>
// yes this is basically a C program 🤷🏻‍

static const int ARBITRARY_MAX_PASSWORD_LENGTH = 50;

bool is_valid(int min, int max, char c, char *password) {
    int count = 0;

    for (int i = 0; i < ARBITRARY_MAX_PASSWORD_LENGTH; i++) {
        if (password[i] == '\0') {
            break;
        }
        count += password[i] == c;
    }

    return count >= min && count <= max;
}

int main(void) {

    int valid = 0;

    int min, max;
    char c;
    char password[ARBITRARY_MAX_PASSWORD_LENGTH + 1];

    while(scanf("%d-%d %c: %s", &min, &max, &c, password) > 0) {
        valid += is_valid(min, max, c, password);
    }

    printf("%d valid passwords\n", valid);

}
