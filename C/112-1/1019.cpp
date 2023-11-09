// 1019

// Author: 四子三丙 陳人輔 C110152319
// Class : 資料結構
// Description : Practice Polynomial function

#include <stdio.h>
#include <stdlib.h>
#define MAX 101

typedef struct {
    int degree;       // Highest order
    float coef[MAX];  // Coefficient of each term
} POLYNOMIAL;

// Only constant or '0'
int IsZero(POLYNOMIAL A) {
    if (A.degree == 0 && A.coef[0] == 0)
        return 1;
    else
        return 0;
}

// return the coefficient of specific term
float Coefficient(POLYNOMIAL A, int exp) {
    return A.coef[exp];
}

// return power of the highest oder term
int LeadExp(POLYNOMIAL A) {
    return A.degree;
}

int main() {
    return 0;
}