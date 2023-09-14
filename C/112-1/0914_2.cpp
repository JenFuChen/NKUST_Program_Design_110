/*
    ｜Practice 2｜
    Author: JEN-FU CHEN, C110152319
    Build Date: 2023.09.14
    Description: compare matrix
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[3][3] = {{78, 23, -12}, {23, -1, 35}, {-92, 54, 38}};
    int b[3][3] = {{-16, 34, -54}, {6, 82, 77}, {24, 33, -7}};
    int c[3][3] = {{0}};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            c[i][j] = a[i][j] > b[i][j] ? a[i][j] : b[i][j];
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}