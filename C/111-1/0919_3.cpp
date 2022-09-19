#include <math.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
// 64%
int main() {
    while (1) {
        char S1[999] = {'\0'}, old[1] = {'\0'}, newC[2] = {'\0'};
        scanf("%s", S1);
        if (strcmp(S1, "bye") == 0 && strlen(S1) == 3) {
            break;
        }
        scanf("%s %s", old, newC);
        for (int i = 0; i < strlen(S1); i++) {
            if (S1[i] == old[0]) {
                printf("%c", newC[0]);
            } else {
                printf("%c", S1[i]);
            }
        }
        printf("\n");
    }

    return 0;
}