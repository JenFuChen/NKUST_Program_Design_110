#include <stdio.h>
#include <iostream>
using namespace std;
void transferDecimal(int num, int base) {
    int temp;
    if (num > 0) {
        transferDecimal(num / base, base);
        temp = num % base;
        if (temp >= 10) {
            printf("%c", temp - 10 + 65);
        } else {
            printf("%d", temp);
        }
    }
}
void transferFloat(double num, int base, int D) {
    double temp;
    int intTemp;
    int arr[D];
    for (int i = 0; i < D; i++) {
        temp = num * base;
        intTemp = (int)temp;
        if (intTemp >= 10) {
            arr[i] = intTemp + 55;
        } else {
            arr[i] = intTemp + '0';
        }
        num = (temp - intTemp * 1.0);
        if (num == 0)
            break;
    }
    for (int i = 0; i < D; i++) {
        printf("%c", arr[i]);
    }
}
int main() {
    double N = 0;
    int B = 0, D = 0;
    while (1) {
        cin >> N >> B >> D;
        // scanf("%lf %d %d", &N, &B, &D);
        if (N <= 0 || (B <= 1 or B > 36) || (D < 0 or D > 5)) {
            break;
        }
        int decimalN = (int)N;
        double floatN = N - decimalN;
        transferDecimal(decimalN, B);
        if (D > 0) {
            printf(".");
            transferFloat(floatN, B, D);
        }
        printf("\n");
    }

    return 0;
}