//印出ASCLL碼
#include <stdio.h>
int main() {
    unsigned char ch = 0;
    while (ch <= 255) {
        printf("%d\n", ch);
        ch = ch + 1;
    }
    return 0;
}