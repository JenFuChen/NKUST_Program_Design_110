#include <stdio.h>

int main() {
    int N = 0;
    
    // while (scanf("%d", &N) != 0) {
    //     // Diamond 
    //     int side = 2 * N - 1;
    //     for (int i = 0; i < side; i++) {
    //         for (int j = 0; j < side; j++) {
    //             if (i <= (N - 1) && j <= (N - 1) && (j + i) == N - 1) {
    //                 printf("*");  // Top Left
    //             } else if (i <= (N - 1) && j > (N - 1) && (j - i) == N - 1) {
    //                 printf("*");  // Top Right
    //             } else if (i > (N - 1) && j <= (N - 1) && (i - j) == N - 1) {
    //                 printf("*");  // Bottom Left
    //             } else if (i > (N - 1) && j > (N - 1) &&
    //                        ((i + j) / 3 == (N - 1)) && (i + j) % 3 == 0) {
    //                 printf("*");  // Bottom Right
    //             } else {
    //                 printf(" ");
    //             }
    //         }
    //         printf("\n");
    //     }
    // }
    return 0;
}