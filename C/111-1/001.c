#include <stdio.h>
// 35%
int main() {
    int min = 100000000, inputNum = 0, N = 0;
    while (1) {
        scanf("%d", &N);
        if (N <= 0) {
            break;
        }
        while (N--) {
            scanf("%d", &inputNum);
            if (inputNum < min) {
                min = inputNum;
            }
        }
        printf("%d\n", min);
        min = 100000000;
    }

    return 0;
}