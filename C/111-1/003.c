#include <stdio.h>
// 0%
int main() {
    while (1) {
        int N = 0;
        scanf("%d", &N);
        if (N <= 0) {
            break;
        }
        for (int i = 1; i <= (2 * N + 1); i++) {
            for (int j = 1; j <= (2 * N + 1); j++) {
                if ((j == 1) || (j == 2 * N + 1)) {
                    printf("|");
                } else if (i == 1 || i == (2 * N + 1)) {
                    printf("=");
                } else if (i == j && i == ((2 * N + 1) / 2) + 1) {
                    printf("*");
                } else if (j <= i) {
                    printf("$");
                } else if (j > (2 * N + 1 - i)) {
                    printf("#");
                } else if (j > i) {
                    printf("@");
                }
            }
            printf("\n");
        }
    }

    return 0;
}