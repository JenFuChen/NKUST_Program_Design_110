// 0928 練習八
// Author: 四子三丙 陳人輔 C110152319
// Class : 資料結構
// Description : Practice struct and pointer

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct string {
    char str[80];
} typedef STRING;

int strComp(STRING A, STRING B) {
    int i = 0;
    while (A.str[i] != '\0' && B.str[i] != '\0') {
        if (A.str[i] == B.str[i])
            i++;
        else if (A.str[i] > B.str[i])
            return 1;
        else
            return -1;
    }
    if (A.str[i] != '\0' && B.str[i] != '\0')
        return 0;
    else if (A.str[i] != '\0')
        return 1;
    else
        return -1;
}

void strSort(STRING* A) {
    STRING temp;
    // printf("// --- SORTING --- //\n");
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            // printf("%d\n", strComp(A[i], A[j]));
            if (strComp(A[i], A[j]) == 1) {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}

int main() {
    STRING A[5];

    for (int i = 0; i < 5; i++) {
        scanf("%s", A[i].str);
    }
    strSort(A);
    printf("// ========== //\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", A[i].str);
    }
    return 0;
}