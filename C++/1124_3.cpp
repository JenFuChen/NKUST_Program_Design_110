#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    while (1) {
        int N, k;
        cin >> N;
        if (N > 9 || N < 1) {
            break;
        }
        for (int i = 0; i < 2 * N - 1; i++) {
            if (i < N) {
                k = i;
            } else {
                k = 2 * (N - 1) - i;
            }
            for (int j = 0; j < k; j++)
                printf("%d", N - j);
            for (int j = 0; j < 2 * (N - k) - 1; j++)
                printf("%d", N - k);
            for (int j = k - 1; j >= 0; j--)
                printf("%d", N - j);
            printf("\n");
        }
    }
}