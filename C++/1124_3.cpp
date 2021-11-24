#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    while (1) {
        int N, x, y, k;
        cin >> N;
        if (N > 9 || N < 1) {
            break;
        }
        for (int i = 1; i < 2 * N; i++) {
            for (int j = 1; j < 2 * N; j++) {
                x = 0;
                y = 0;
                if (i >= N)
                    y = i - N;
                else
                    y = N - i;

                if (j >= N)
                    x = j - N;
                else
                    x = N - j;
                if (y >= x)
                    k = y;
                else
                    k = x;
                printf("%d", k + 1);
            }
            printf("\n");
        }
    }
}