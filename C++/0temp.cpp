#include <stdio.h>

int main() {
    int n, x[100000] = {0}, y[100000] = {0}, tem;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (x[j] > x[j + 1]) {  //先對x做排序
                tem = x[j + 1];
                x[j + 1] = x[j];
                x[j] = tem;
                
                tem = y[j + 1];
                y[j + 1] = y[j];
                y[j] = tem;
            }

            if (x[j] == x[j + 1] &&
                y[j] > y[j + 1]) {  // x和x+1相同的情況下再對y做排序

                tem = y[j + 1];

                y[j + 1] = y[j];

                y[j] = tem;

                tem = x[j + 1];

                x[j + 1] = x[j];

                x[j] = tem;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d %d\n", x[i], y[i]);
    }

    return 0;
}