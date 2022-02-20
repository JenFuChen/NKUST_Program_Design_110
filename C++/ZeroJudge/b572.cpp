#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, i = 0, cnt = 0, cntM3 = 0;
    scanf("%d", &N);
    if (N <= 0) {
        return 0;
    }
    int timeNow[2 * N], timeBus[2 * N], timeRun[N];
    while (N--) {
        scanf("%d %d %d %d %d", &timeNow[i], &timeNow[i + 1], &timeBus[i],
              &timeBus[i + 1], &timeRun[cnt]);
        i += 2;
        cnt++;
    }
    i = 0;
    while (cnt--) {
        if ((timeNow[i + 1] + timeRun[cntM3]) % 60 > timeBus[i + 1] ||
            (timeNow[i] + (timeNow[i + 1] + timeRun[cntM3]) / 60) >
                timeBus[i]) {
            printf("No\n");
        } else {
            printf("Yes\n");
        }
        i += 2;
        cntM3 += 1;
    }

    return 0;
}
