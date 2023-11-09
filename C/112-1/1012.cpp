// 1012

// Author: 四子三丙 陳人輔 C110152319
// Class : 資料結構
// Description : Practice Recursion
#include <stdio.h>

int pow(int x, int n) {
    if (n == 0)
        return 1;
    else if (n == 1)
        return x;
    else
        return x * pow(x, n - 1);
}
int main() {
    while (1) {
        int x, y = 0;
        printf("Please input x, n: ");
        scanf("%d %d", &x, &y);
        if (x <= 0 || y < 0) {
            printf("EXIT\n");
            break;
        }
        printf("%d ^ %d = %d \n", x, y, pow(x, y));
    }

    return 0;
}