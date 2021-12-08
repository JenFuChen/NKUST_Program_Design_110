#include <stdio.h>
#include <iostream>
using namespace std;
void tree(int level) {
    for (int m = 1; m <= 3; m++) {
        for (int i = 0; i < level * m; i++) {
            for (int j = i; j < 3 * level - 1; j++) {
                printf("^");
            }
            for (int k = 0; k <= i; k++) {
                printf("* ");
            }
            printf("\n");
        }
    }
    return;
}
int main() {
    while (1) {
        int func1, level;
        scanf("%d %d", &func1, &level);
        if (func1 > 2 || func1 < 1 || level <= 0) {
            break;
        }
        if (func1 == 1) {
            for (int x = 1; x < 2 * level; x++) {
                for (int y = 1; y < 2 * level; y++) {
                    printf("(%d,%d)", x, y);
                    if (x == y) {
                        printf("\\  ");
                    }
                }
                printf("\n");
            }
        }
        if (func1 == 2) {
            tree(level);
        }
        return 0;
    }
}