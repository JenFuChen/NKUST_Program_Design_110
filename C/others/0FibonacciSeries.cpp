#include <stdio.h>
#include <iostream>
using namespace std;
int main() {
    //費氏數列
    int sum, n = 0;
    while (cin >> n, n >= 0) {
        int temp = 1;
        int temp2 = 1;
        for (int i = 0; i <= n; i++) {
            if (n == 1 || n == 0) {
                sum = 1;
            } else if (i > 1) {
                sum = temp + temp2;
                temp = temp2;
                temp2 = sum;
            }
        }
        printf("Sum = %d\n", sum);
    }
    return 0;
}