#include <stdio.h>

int main() {
    while (1) {
        int N;
        scanf("%d", &N);
        if (N <= 0) {
            break;
        }
        int O, min, max;
        scanf("%d", &O);
        int array[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &array[i]);
        }
        if (O == 1) {
            min = array[0];
            for (int i = 1; i < N; i++) {
                if (min > array[i]) {
                    min = array[i];
                }
            }
            printf("%d", min);
            for (int i = 1; i <= min; i++) {
                printf("*");
            }
        }
        if (O == 2) {
            max = array[0];
            for (int i = 1; i < N; i++) {
                if (max < array[i]) {
                    max = array[i];
                }
            }
            printf("%d", max);
            for (int i = 1; i <= max; i++) {
                printf("*");
            }
        }
        printf("\n");
    }
    return 0;
}