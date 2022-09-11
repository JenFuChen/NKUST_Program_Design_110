// A915 Finished
#include <stdio.h>

int main() {
    int line = 0, cnt = 0, temp = 0;
    scanf("%d", &line);
    if (line > 1000 || line < 1) {
        return 0;
    }
    int x[line], y[line];
    while (line--) {
        scanf("%d %d", &x[cnt], &y[cnt]);
        cnt += 1;
    }
    for (int i = 0; i < cnt; i++) {
        for (int j = i + 1; j < cnt; j++) {
            if (x[j] < x[i]) {
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
                //////
                temp = y[i];
                y[i] = y[j];
                y[j] = temp;
            }
            if (x[j] == x[i] && y[j] < y[i]) {
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
                //////
                temp = y[i];
                y[i] = y[j];
                y[j] = temp;
            }
        }
    }
    for (int i = 0; i < cnt; i++) {
        printf("%d %d\n", x[i], y[i]);
    }
    return 0;
}
