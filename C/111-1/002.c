#include <stdio.h>

int main() {
    while (1) {
        int N = 0, cnt = 0, check = 0;
        int inputNum[99] = {};
        scanf("%d", &N);
        if (N <= 0) {
            break;
        }
        // printf("----1\n");
        getchar();
        // printf("----2\n");
        while (N--) {
            scanf("%d", &inputNum[cnt]);
            cnt++;
        }
        // printf("----3\n");
        for (int i = 1; i < 99999999; i++) {
            for (int j = 0; j < cnt; j++) {
                if (i % inputNum[j] == 0) {
                    check += 1;
                }
                if (check == cnt) {
                    printf("%d\n", i);
                    break;
                }
                // printf("-----4\n");
            }
            if (check == cnt) {
                break;
            } else {
                check = 0;
            }
        }
    }

    return 0;
}