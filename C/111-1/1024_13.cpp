#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Done  : 1026
// Result: 45 % similar to others' ! ==...

int main() {
    while (true) {
        int scoreData[99][99] = {0};
        char subject[99][99] = {'\0'};
        int studentNum[99] = {0};
        int N, S = 0;
        float sum = 0;
        scanf("%d %d", &S, &N);
        getchar();
        if (S <= 0 || N <= 0) {
            break;
        }
        for (int i = 0; i < S; i++) {
            scanf("%s", subject[i]);
        }
        getchar();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < S; j++) {
                scanf("%d", &scoreData[i][j]);
            }
        }
        getchar();
        printf("學生編號 ");
        for (int i = 0; i < S; i++) {
            printf("%s ", subject[i]);
        }
        printf("學生平均\n");
        for (int i = 0; i < N; i++) {
            printf("%d ", i + 1);
            for (int j = 0; j < S; j++) {
                printf("%d ", scoreData[i][j]);
                sum += scoreData[i][j];
            }
            printf("%.2f\n", sum / S);
            sum = 0;
        }
        printf("各科平均 ");
        for (int i = 0; i < S; i++) {
            for (int j = 0; j < N; j++) {
                sum += scoreData[j][i];
            }
            printf("%.2f ", sum / N);
            sum = 0;
        }
        printf("\n");
    }
    return 0;
}