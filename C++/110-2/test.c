// 0221 期初加分作業
#include <stdio.h>

int main() {
    int N, i = 1, cnt = 0;
    int list[99] = {0};
    scanf("%d", &list[0]);
    while (list[i - 1] > 0) {
        scanf("%d", &list[i]);
        i++;
    }
    while (list[cnt] > 0) {
        printf("Hell Everyone, %d\n", list[cnt]);
        cnt++;
    }
    return 0;
}