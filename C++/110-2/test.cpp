#include <math.h>
#include <stdio.h>

int main() {
    char test[99][11];
    long num[99][0];
    int temp = 0;
    scanf("%s", test[0]);
    for (int i = 0; i < 11; i++) {
        printf("%c\n", test[0][i]);
    }
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) {
            continue;
        } else {
            temp = (test[0][i] - 48) + temp * 10;
            printf("temp : %d\n", temp);
        }
    }
    printf("------------\n");
    printf("%d \n", temp);
    // printf("%s", test[0]);
    return 0;
}