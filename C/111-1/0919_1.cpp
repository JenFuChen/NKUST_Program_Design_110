#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 42%
/*======<格式化輸出>=======*/
void is_int(int x) {
    printf("%d\n", x);
}
void is_char(char x) {
    printf("%c\n", x);
}
void is_string(char* x) {
    printf("%s\n", x);
}
void is_double(double x) {
    printf("%f", x);
}
void is_float(float x) {
    printf("%.2f\n", x);
}
#define print(X) \
    _Generic((X),int:is_int,\
    char:is_char,\
    char *:is_string,\
    double:is_double,\
    default:is_float\
    )(X)
// std::cout << "----2\n";

// 尚未完成
int reverse(int num) {
    int result = 0, cnt = 0, power = 0;
    int old_num = num;
    while (old_num > 0) {
        cnt += 1;
        old_num /= 10;
    }
    power = pow(10, cnt - 1);
    while (num > 0) {
        result += power * (num % 10);
        num /= 10;
        power /= 10;
    }
    return result;
}
int main() {
    int num1 = 0, num2 = 0, sub = 0, reverseNum = 0;
    while (scanf("%d %d", &num1, &num2) != EOF) {
        if (num1 == -1 && num2 == -1) {
            break;
        }
        sub = num1 - num2;
        if (sub < 0) {
            printf("Error\n");
        } else {
            is_float(sqrt(reverse(sub)));
        }
    }
    return 0;
}
