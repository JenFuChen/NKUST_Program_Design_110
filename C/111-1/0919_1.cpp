#include <math.h>
#include <stdio.h>
#include <iostream>
// std::cout << "----2\n";

// 尚未完成
int reverse(int num) {
    int result = 0, cnt = 0;
    while (num > 0) {
        result = num % 10 + pow(10, cnt) * result;
        num /= 10;
        cnt++;
    }
    return result;
}
int main() {
    while (1) {
        long long int num1 = 0, num2 = 0, sub = 0, reverseNum = 0;
        double answer = 0;
        scanf("%lld %lld", &num1, &num2);
        if (num1 == -1 && num2 == -1) {
            break;
        }
        sub = num1 - num2;
        if (sub < 0) {
            std::cout << "Error" << std::endl;
        } else {
            reverseNum = reverse(sub);
            answer = sqrt(reverseNum);
            printf("%.2f\n", answer);
        }
    }
    return 0;
}