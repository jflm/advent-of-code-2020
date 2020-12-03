#include <stdio.h>
#include <string.h>
#include <vector>
#include <memory>

struct slope {
    int right, down;
    int x_pos = 0, y_pos = 0;
    int c_trees = 0;
    slope(int, int);
};

slope::slope(int r, int d): right{r}, down{d} {}

int main(void) {

    static const int MAX_LINE_WIDTH = 50;
    int line_width = 0;

    const std::vector<std::shared_ptr<slope>> slopes {
            std::shared_ptr<slope>{new slope{1, 1} },
            std::shared_ptr<slope>{new slope{3, 1} },
            std::shared_ptr<slope>{new slope{5, 1} },
            std::shared_ptr<slope>{new slope{7, 1} },
            std::shared_ptr<slope>{new slope{1, 2} }
    };

    char line[MAX_LINE_WIDTH];
    while (scanf("%s", line) > 0) {

        if (line_width == 0) {
            line_width = strlen(line);
        }

        for (auto &s : slopes) {
            if (s->y_pos % s->down == 0) {
                s->c_trees += line[s->x_pos] == '#';
                s->x_pos += s->right;
            }
            s->y_pos++;

            if (s->x_pos > line_width - 1) {
                s->x_pos -= line_width;
            }
        }

    }

    long long tree_product = 1;
    for (auto &slope : slopes) {
        printf("r %d, d %d -> %d trees\n", slope->right, slope->down, slope->c_trees);
        tree_product *= slope->c_trees;
    }

    printf("Product: %lld\n", tree_product);

}
