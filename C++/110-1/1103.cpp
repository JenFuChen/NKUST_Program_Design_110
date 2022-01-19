//０５ min - max 總和 、 乘積
#include <stdio.h>
#include <iostream>
using namespace std;
int main() {
    int cnt = 0;
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; i++) {
        int mod = 0, num1 = 0, num2 = 0, sum = 0, multi = 1, min1 = 0, max1 = 0;
        scanf("%d%d%d", &mod, &num1, &num2);
        if (num1 > num2) {
            max1 = num1;
            min1 = num2;
        } else {
            max1 = num2;
            min1 = num1;
        }
        if (mod == 1) {
            for (int i = min1; i <= max1; i++) {
                sum = sum + i;
            }
            printf("%d\n", sum);
        }
        if (mod == 2) {
            for (int i = min1; i <= max1; i++) {
                multi = multi * i;
            }
            printf("%d\n", multi);
        }
    }
    return 0;
}