#include <stdio.h>
#include <iostream>
using namespace std;
int main() {
    while (1) {
        int N = 0;
        scanf("%d", &N);
        if (N <= 0) {
            break;
        }
        int list[N];
        for (int i = 0; i < N; i++) {
            list[i] = 0;
        }

        int check = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d", &list[i]);
        }
        sort(list, list + N);
        for (int i = list[2]; i <= 1000; i++) {
            if (i % list[0] == 0 && i % list[1] == 0 && i % list[2] == 0 &&
                check == 0) {
                printf("%d\n", i);
                check = 1;
            }
        }
    }

    return 0;
}