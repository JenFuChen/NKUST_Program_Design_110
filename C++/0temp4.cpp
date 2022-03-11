#include <stdio.h>

int main(int argc, const char* argv[]) {
    int num;
    while (1) {
        scanf("%d", &num);
        if (num > 100)
            break;
    }
    while (num) {
        printf("%d", num % 10);
        num /= 10;
    }
    printf("\n");
    return 0;
}