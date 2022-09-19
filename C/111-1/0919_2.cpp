#include <math.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
// 11%
int main() {
    while (1) {
        char S1[999] = {'\0'}, S2[999] = {'\0'};
        int ans = 0, i = 0;
        scanf("%s", S1);
        scanf("%s", S2);
        int len1 = strlen(S1);
        int len2 = strlen(S2);
        if (strcmp(S1, "bye") == 0 && len1 == 3) {
            break;
        }
        if (strcmp(S2, "bye") == 0 && len2 == 3) {
            break;
        }
        int max = (len1 > len2 ? len1 : len2);
        for (int i = 0; i < max; i++) {
            if (i > len1) {
                printf("-%d ", S2[i]);
            } else {
                printf("%d ", S1[i] - S2[i]);
            }
        }
        printf("\n");
    }

    return 0;
}