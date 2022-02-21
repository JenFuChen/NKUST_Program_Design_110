// 0221 Addition Test
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, newN, temp;
    while (scanf("%d", &N)) {
        int cnt = 0;
        newN = N;
        if (N <= 0) {
            break;
        }
        int list[99] = {0};
        while (N--) {
            scanf("%d", &list[cnt]);
            cnt++;
        }
        for (int i = 0; i < newN; i++) {
            for (int j = i + 1; j < newN; j++) {
                if (list[j] > list[i]) {
                    temp = list[i];
                    list[i] = list[j];
                    list[j] = temp;
                  }
            }
        }
        printf("Minimum value is %d\n", list[newN - 1]);
        printf("Maximum value is %d\n", list[0]);
        for (int i = 0; i < newN; i++) {
            printf("%d ", list[i]);
        }
        printf("\n");
    }
    return 0;
}