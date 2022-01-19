#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    while (1) {
        int O, N, cnt = 0;
        cin >> O >> N;
        if (O > 3 || O < 1 || N <= 0) {
            break;
        }
        if (O == 1) {
            for (int i = N; i > 0; i--) {
                cnt = N - i;
                for (int k = 0; k < cnt; k++) {
                    printf(" ");
                }
                for (int j = 0; j < i; j++) {
                    printf("*");
                }
                printf("\n");
            }
        }
        if (O == 2) {
            for (int i = 0; i < N; i++) {
                for (int k = 0; k < N - i; k++) {
                    printf(" ");
                }
                for (int j = 0; j <= i; j++) {
                    printf("* ");
                }
                printf("\n");
            }
        }
    }
    return 0;
}