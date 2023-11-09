// 1012

// Author: 四子三丙 陳人輔 C110152319
// Class : 資料結構
// Description : 輾轉相除法求公因數,使用遞迴

#include <stdio.h>

int GCD(int x, int y) {
    if (x % y == 0)
        return y;
    else
        return GCD(y, x % y);
}
int main() {
    while (1) {
        int x, y = 0;
        printf("Please input x, y: ");
        scanf("%d %d", &x, &y);
        if (x <= 0 || y < 0) {
            printf("EXIT\n");
            break;
        }
        printf("GCD(%d , %d) = %d \n", x, y, GCD(x, y));
    }

    return 0;
}