// 0221 Addition Test
#include <stdio.h>

int main() {
    int num[99] = {0}, num2[99] = {0};
    int cnt = 0;
    scanf("%d %d", &num[0], &num2[0]);
    while ((num[cnt] == 1 || num[cnt] == 2) && num2[cnt] > 0) {
        cnt++;
        scanf("%d %d", &num[cnt], &num2[cnt]);
    }
    cnt = 0;
    while (num2[cnt] > 0) {
        if (num[cnt] == 1) {
            for (int i = 0; i < num2[cnt]; i++) {
                for (int j = 0; j <= i; j++) {
                    printf("*");
                }
                printf("\n");
            }
        }
        if (num[cnt] == 2) {
            for (int i = 1; i <= num2[cnt]; ++i) {
                for (int k = 0; k <= i - 1; k++)
                    printf(" ");
                for (int j = num2[cnt] - i; j >= 0; j--)
                    printf("* ");
                printf("\n");
            }
        }
        cnt++;
    }
    return 0;
}