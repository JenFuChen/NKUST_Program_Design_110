// 1102

// Author: 四子三丙 陳人輔 C110152319
// Class : 資料結構
// Description : Sparse Matrix 稀疏矩陣

#include <stdio.h>
#include <stdlib.h>

#define MAX 101
#define MAX_COL 101

typedef struct {
    int row;
    int col;
    int value;
} Term;

void printMat(Term* a, int n) {
    printf("-------------------------------------------------\n");
    printf("\tROW\t|\tCOL\t|\tVALUE\t|\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("[%d]\t%d\t|\t%d\t|\t%d\t|\n", i, a[i].row, a[i].col,
               a[i].value);
    }
    printf("-------------------------------------------------\n\n");
}

void Transpose(Term* a, Term* b) {
    // Transpose A into B
    int n, currentTb;
    n = a[0].value;
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = n;
    if (n > 0) {
        currentTb = 1;
        for (int i = 0; i < a[0].col; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[j].col == i) {
                    b[currentTb].row = a[j].col;
                    b[currentTb].col = a[j].row;
                    b[currentTb].value = a[j].value;
                    currentTb++;
                }
            }
        }
    }
}

void fastTranspose(Term* a, Term* b) {
    int test = 0;
    // printf("\n-%d-\n", test++);
    int j = 0;
    int rowTerms[MAX], startingPos[MAX];
    int numCols = a[0].col, numTerms = a[0].value;
    b[0].row = numCols;
    b[0].col = a[0].row;
    b[0].value = numTerms;
    if (numTerms > 0) {
        // Summaries the col of "A matrix"
        for (int i = 0; i < numCols; i++) {
            rowTerms[i] = 0;
        }
        for (int i = 1; i <= numTerms; i++) {
            rowTerms[a[i].col]++;
        }
        startingPos[0] = 1;
        for (int i = 1; i < numCols; i++) {
            startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
        }
        for (int i = 1; i <= numTerms; i++) {
            j = startingPos[a[i].col]++;
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].value = a[i].value;
        }
    }
}

int main() {
    Term a[MAX] = {{6, 6, 8}, {0, 0, 15}, {0, 3, 22}, {0, 5, -15}, {1, 1, 11},
                   {1, 2, 3}, {2, 3, -6}, {4, 0, 91}, {5, 2, 28}};
    Term b[MAX] = {
        {0, 0, 0},
    };
    Term c[MAX] = {
        {0, 0, 0},
    };
    printf("\t\tORIGINAL\n");
    printMat(a, a[0].value + 1);

    printf("\t\tTRANSPOSE\n");
    Transpose(a, b);
    printMat(b, b[0].value + 1);

    printf("\t\tFAST TRANSPOSE\n");
    fastTranspose(a, c);
    printMat(c, c[0].value + 1);
    return 0;
}