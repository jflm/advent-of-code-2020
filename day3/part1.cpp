#include <stdio.h>
#include <string.h>

int main(void) {

    static const int MAX_LINE_WIDTH = 50;

    const int m_right = 3;

    int x = 0;
    int line_width = 0;
    int c_trees = 0;

    char line[MAX_LINE_WIDTH];
    while (scanf("%s", line) > 0) {
        if (line_width == 0) {
            line_width = strlen(line);
        }

        c_trees += line[x] == '#';

        x += m_right;
        if (x > line_width - 1) {
            x -= line_width;
        }
    }

    printf("Trees: %d\n", c_trees);

}
