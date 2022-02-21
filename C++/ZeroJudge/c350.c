// C350 Finished
#include <stdio.h>

int main() {
    int N, K, W, sum, newN;
    scanf("%d %d %d", &N, &K, &W);
    sum = N;
    while (N >= K) {
        sum = sum + (N / K) * W;
        N = (N / K) * W + (N % K);
    }
    printf("%d\n", sum);
    return 0;
}