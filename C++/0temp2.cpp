#include <math.h>
#include <stdio.h>
#include <iostream>
int a, b, i, f;
void devide(int n) {
    int l = 0;
    int m = 0;
    int s = 0;
    a = n;
    while (a != 0) {
        a = a / 10;
        s++;
    }  //算位數
    for (i = s; i > 0; i--) {
        b = n % 10;
        n = n / 10;
        if ((s - i) % 2 == 0) {
            m = b * pow(10, (s - i) / 2) + m;
        } else
            l = b * pow(10, (s - i) / 2) + l;
    }
    f = m - l;
    printf("%d-%d=%d\n", m, l, f);  //求相減後的值
}
int main() {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n <= 0)
            break;
        devide(n);
        while (f >= 10) {
            devide(f);
        }
    }
    return 0;
}
