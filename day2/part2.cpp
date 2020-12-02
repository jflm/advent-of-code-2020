#include <stdio.h>

static const int ARBITRARY_MAX_PASSWORD_LENGTH = 50;

bool is_valid(int pos1, int pos2, char c, char *password) {
    bool at_least_one_in_position = password[pos1 - 1] == c || password[pos2 - 1] == c;
    bool both_in_position = password[pos1 - 1] == c && password[pos2 - 1] == c;
    return at_least_one_in_position && !both_in_position;
}

int main(void) {

    int valid = 0;

    int pos1, pos2;
    char c;
    char password[ARBITRARY_MAX_PASSWORD_LENGTH + 1];

    while(scanf("%d-%d %c: %s", &pos1, &pos2, &c, password) > 0) {
        valid += is_valid(pos1, pos2, c, password);
    }

    printf("%d valid passwords.\n", valid);

}
