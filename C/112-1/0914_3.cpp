/*
    ｜Practice 3｜
    Author: JEN-FU CHEN, C110152319
    Build Date: 2023.09.14
    Description: compute average of matrix and compare with average
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[3][3] = {{-8, 23, -12}, {23, -4, 35}, {-9, 54, 38}};
    int average = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            average += a[i][j];
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    average = average / 10;
    printf("Matrix Average = %d\n", average);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", a[i][j] > 1 ? 1 : 0);
        }
        printf("\n");
    }
    return 0;
}