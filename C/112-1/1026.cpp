// 1026

// Author: 四子三丙 陳人輔 C110152319
// Class : 資料結構
// Description : Practice Polynomial function

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define TRUE 1
#define FALSE 0

struct poly {
    int degree;       // Highest order
    float coef[MAX];  // Coefficient of each term
};

typedef struct poly POLY;

// Preset the value of polynomial by zero
POLY Zero() {
    POLY result;
    result.degree = 0;
    for (int i = 0; i < MAX; i++)
        result.coef[i] = 0;
    return result;
}

// Detect if the poly is zero
int IsZero(POLY A) {
    if (A.degree == 0 && A.coef[0] == 0)
        return 1;
    else
        return 0;
}

// Return the coefficient of the e order term
float Coef(POLY A, int e) {
    return A.coef[e];
}

// Return the highest order coefficient
int LeadExp(POLY A) {
    return A.degree;
}

// Add the coefficient of "e" order term
POLY Attach(POLY A, int c, int e) {
    if (Coef(A, e) == 0) {
        if (LeadExp(A) < e) {
            A.degree = e;
            A.coef[e] = c;
        }
    }
    return A;
}

// Remove the e order term coefficient
POLY Remove(POLY A, int e) {
    printf("rm 第%d次項 ", e);
    A.coef[e] = 0;
    if (A.degree == e) {
        // If remove the highest degree, renew the degree of polynomial A
        for (int i = A.degree - 1; i >= 0; i--) {
            if (A.coef[i] != 0) {
                A.degree = i;
                break;
            }
        }
    }
    return A;
}

// Add two polynomial and return the result
POLY ADD(POLY A, POLY B) {
    POLY result;
    for (int i = A.degree >= B.degree ? A.degree : B.degree; i >= 0; i--) {
        result.coef[i] = A.coef[i] + B.coef[i];
    }
    result.degree = A.degree >= B.degree ? A.degree : B.degree;
    // Prevent it from the lead coefficient is 0
    for (int i = result.degree; i >= 0; i--) {
        if (result.coef[i] != 0) {
            result.degree = i;
            break;
        }
    }
    return result;
}

// Print out the coefficient of each degree
void printPOLY(POLY A) {
    printf("\nA = ");
    for (int i = A.degree; i >= 0; i--) {
        printf("%.0f ", A.coef[i]);
    }
    printf("\n");
}

// Single term mutiple function
POLY singleMult(POLY A, float c, int e) {
    POLY result = Zero();
    if (c == 0 && e == 0) {
        return result;
    } else {
        for (int i = 0; i <= A.degree; i++) {
            result.coef[i + e] = A.coef[i] * c;
        }
        result.degree = A.degree + e;
    }
    return result;
}

// Mutiple function
POLY Mult(POLY A, POLY B) {
    POLY result = Zero();
    while (!IsZero(B)) {
        result = ADD(result, singleMult(A, Coef(B, LeadExp(B)), LeadExp(B)));
        B = Remove(B, LeadExp(B));
    }
    return result;
}

int main() {
    POLY A = {
        0,
        0,
    };
    //  Set 3x^4 + 2x + 1
    A.degree = 4;
    A.coef[4] = 3;
    A.coef[1] = 2;
    A.coef[0] = 1;
    printf("\n// ===== START ===== //\n");
    printPOLY(A);
    if (IsZero(A))
        printf("A是零次多項式\n");  // 零次多項式
    else
        printf("A是%d次多項式，其最高次係數為%.0f \n", LeadExp(A),
               Coef(A, LeadExp(A)));
    A = Attach(A, -6, 5);  // -6 3 0 0 2 1
    printPOLY(A);
    printf("A是%d次多項式，其最高次係數為%.0f \n", LeadExp(A),
           Coef(A, LeadExp(A)));
    printf("\n----------\n");
    A = Remove(A, 1);  // -6 3 0 0 0 1
    printPOLY(A);
    printf("\n----------\n");
    A = Remove(A, 5);  // 3 0 0 0 1
    printPOLY(A);
    printf("\n----------\n");
    A = Remove(A, 4);  // 1
    printPOLY(A);
    printf("\n----------\n");
    POLY B = Zero();
    B.degree = 1;
    B.coef[0] = 1;
    B.coef[1] = 2;
    printf("\n----------\n");
    printf("B = 2x + 1");
    printf("\nADD  A + B \n");
    A = ADD(A, B);  // 2 2
    printPOLY(A);
    printf("\n----------\n");
    printf("Multiple with (2x)");
    A = singleMult(A, 2, 1);  // 4 4 0
    printPOLY(A);
    printf("\n----------\n");
    printf("A Mutiple with (2x + 1)\n");
    A = Mult(A, B);  // 8 12 4 0
    printf("\nA*B");
    printPOLY(A);
    printf("");
    return 0;
}