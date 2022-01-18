#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int main() {
    while (1) {
        int num = 0, num2 = 0, min = 0, temp = 0;
        int A_Z[52];
        char data[1000002] = {};
        int countA[52] = {0};  //大寫
        scanf("%d", &num);
        if (num <= 0) {
            break;
        }
        for (int i = 0; i < num; i++) {
            scanf("%s", &data[i]);
            for (int i = 0; num; i++) {
                for (int j = 65; j < 91; j++) {
                    A_Z[j - 65] = j;
                    if ((int)data[i][] == j) {
                        countA[j - 65] += 1;
                    }
                }
                for (int j = 97; j < 123; j++) {
                    A_Z[j - 97 + 26] = j;
                    if ((int)data[i] == j) {
                        countA[j - 97 + 26] += 1;
                    }
                }
            }
        }

        for (int i = 0; i < 52; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (countA[j] < countA[i]) {
                    min = countA[j];
                    countA[j] = countA[i];
                    countA[i] = min;
                    ////////
                    temp = A_Z[j];
                    A_Z[j] = A_Z[i];
                    A_Z[i] = temp;
                }
            }
        }
        for (int i = 0; i < 26; i++) {
            if (countA[i] != 0) {
                printf("%c(%d) ", A_Z[i], countA[i]);
            }
        }
        printf("\n");
        for (int i = 0; i < 52; i++) {
            countA[i] = 0;
        }
    }
}
