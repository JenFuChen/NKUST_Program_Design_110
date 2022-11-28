#include <stdio.h>
#include <iostream>
using namespace std;
int main() {
    int cnt, num = 0;
    while (1) {
        scanf("%d %d", &cnt, &num);
        if (cnt > 26 || cnt < 1 || num <= 0) {
            break;
        }
        for (int x = 1; x < 2 * num; x++) {
            for (int y = 1; y < 2 * num; y++) {
                // printf("(%d,%d) ", x, y);
                int min =
                    abs(num - x) > abs(num - y) ? abs(num - y) : abs(num - x);
                // printf("\033[%dm %c \033[m   ",min %cnt+30, min % cnt + 65);
                printf("%c   ", min % cnt + 65);
            }
            printf("\n\n");
        }
    }
    return 0;
}