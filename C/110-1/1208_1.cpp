#include <stdio.h>
#include <iostream>
using namespace std;
int func, level, cnt;
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
}
void amulet(int level) {
    cnt = 2 * level - 1;
    for (int x = 1; x < 2 * level; x++) {
        for (int y = 1; y < 2 * level; y++) {
            if (x == level && y == level) {
                printf("*");  //中心
            } else if (x == 1 || x == cnt) {
                printf("-");  //邊界
            } else if (y == 1 || y == cnt) {
                printf("|");  //邊界
            } else if (x == y && (x + y) != 2 * level) {
                printf("\\");  //斜線
            } else if ((x + y) == 2 * level) {
                printf("/");  //斜線
            } else if ((x - y) < 0) {
                if ((x + y) < cnt + 1) {
                    printf("&");  //上
                }
                if ((x + y) > cnt + 1) {
                    printf("$");  //右
                }
            } else if ((x - y) > 0) {
                if ((x + y) < cnt + 1) {
                    printf("@");  //左
                }
                if ((x + y) > cnt + 1) {
                    printf("%%");  //下
                    // cout<<"%";
                }
            }
        }
        printf("\n");
    }
}
int main() {
    while (1) {
        scanf("%d %d", &func, &level);
        if (func > 2 || func < 1 || level <= 0) {
            break;
        }
        if (func == 1) {
            amulet(level);
        }
        if (func == 2) {
            tree(level);
        }
    }
    return 0;
}