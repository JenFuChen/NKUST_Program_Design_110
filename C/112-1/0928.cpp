// 0928

// Author: 四子三丙 陳人輔 C110152319
// Class : 資料結構
// Description : Practice pointer

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct circle {
    float r;
    float x;
    float y;
};

typedef struct circle CL;

float distanceAB(CL* a, CL* b) {
    return sqrt((a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y));
    ;
}

void relation(CL* a, CL* b) {
    float D = distanceAB(a, b);
    float r1 = a->r, r2 = b->r;
    if (D > (r1 + r2)) {
        printf("外離");
    } else if (D == (r1 + r2)) {
        printf("外切");
    } else if ((r1 + r2) > D && D > fabs(r1 - r2)) {
        printf("相交");
    } else if (D == fabs(r1 - r2)) {
        printf("內切");
    } else if (D < fabs(r1 - r2)) {
        printf("內離");
    }
}
int main() {
    CL A = {3, 1, -2};
    CL B = {5, 3, 4};
    CL C = {2, -3, 1};

    float AB, AC, BC = 0;

    AB = distanceAB(&A, &B);
    AC = distanceAB(&A, &C);
    BC = distanceAB(&B, &C);

    printf("AB = %.2f , \tAC = %.2f , \tBC = %.2f\n", AB, AC, BC);
    printf("AB ");
    relation(&A, &B);
    printf(", \tAC ");
    relation(&A, &C);
    printf(", \tBC ");
    relation(&B, &C);

    printf("\n");
    return 0;
}
