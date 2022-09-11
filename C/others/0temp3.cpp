#include <stdio.h>
int main() {
    while (1) {
        int num;
        scanf("%d", &num);
        if (num < 1) {
            break;
        } else {
            int max, min, i, j, k, m, maxnum, minmun;
            int tab[99] = {0};
            for (i = 0; i < num; i += 1) {
                scanf("%d", &tab[i]);
            }
            for (j = 0; j < num; j += 1) {
                for (k = 0; k < (num - j); k += 1) {
                    if (tab[k] < tab[k - 1]) {
                        max = tab[k - 1];
                        min = tab[k];
                        tab[k] = max;
                        tab[k - 1] = min;
                    }
                }
            }
            printf("Minimum value is %d", tab[0]);
            printf("\n");
            printf("Maximum value is %d", tab[num - 1]);
            printf("\n");
            for (k = num - 1; k >= 0; k -= 1) {
                printf("%d ", tab[k]);
            }
            printf("\n");
        }
    }
    return 0;
}