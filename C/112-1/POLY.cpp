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

int IsZero(POLY A) {
    if (A.degree == 0 && A.coef[0] == 0)
        return 1;
    else
        return 0;
}

int Coef(POLY A, int e) {  // e 是傳入的第幾次方項
    return A.coef[e];
}

int LeadExp(POLY A) {  // 回傳最高次方項係數
    return A.degree;
}

POLY Attach(POLY A, int c, int e) {  // 插入第e項次的係數c
    if (Coef(A, e) == 0) {
        if (LeadExp(A) < e) {
            A.degree = e;
            A.coef[e] = c;
        }
    }
    return A;
}

POLY Remove(POLY A, int e) {  // 移除第e次項係數
    printf("rm 第%d次項 ", e);
    if (A.degree == e) {  // 如果刪除的是最高次項 要重新檢查最高次
        for (int i = A.degree - 1; i >= 0; i--) {
            if (A.coef[i] != 0) {
                A.degree = i;  // 設定最高次為第i個發現不為0的次項
                break;
            }
        }
    } else {
        A.coef[e] = 0;
    }
    return A;
}

POLY ADD(POLY A, POLY B) {
    POLY temp;
    for (int i = A.degree >= B.degree ? A.degree : B.degree; i >= 0; i--) {
        temp.coef[i] = A.coef[i] + B.coef[i];
    }
    // Prevent it from the lead coef is 0
    for (int i = temp.degree; i >= 0; i--) {
        if (temp.coef[i] != 0) {
            temp.degree = i;
            break;
        }
    }
    return temp;
}

void printPOLY(POLY A) {
    printf("A = ");
    for (int i = A.degree; i >= 0; i--) {
        printf("%.0f ", A.coef[i]);
    }
    printf("\n");
}

int main() {
    POLY A = {
        0,
        0,
    };
    A.degree = 4;
    A.coef[4] = 3;
    A.coef[1] = 2;
    A.coef[0] = 1;
    printf("\n// ===== START ===== //\n");
    printPOLY(A);
    if (IsZero(A))
        printf("A是零次多項式\n");  // 零次多項式
    else
        printf("A是%d次多項式，其最高次係數為%d \n", LeadExp(A),
               Coef(A, LeadExp(A)));

    A = Attach(A, -6, 5);
    printPOLY(A);
    printf("A是%d次多項式，其最高次係數為%d \n", LeadExp(A),
           Coef(A, LeadExp(A)));
    A = Remove(A, 1);
    printPOLY(A);
    A = Remove(A, 5);
    printPOLY(A);
    A = Remove(A, 4);
    printPOLY(A);
    printf("--");
    POLY B = {
        0,
        0,
    };
    B.degree = 1;
    B.coef[0] = 1;
    B.coef[1] = 2;
    printf("--");
    A = ADD(A, B);
    printPOLY(A);
    printf("");
    return 0;
}
