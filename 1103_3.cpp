// 07 最小公倍數
#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int list[3] = {0, 0, 0};
    for (int i = 0; i < 3; i++) {
        int check = 0;
        for (int i = 0; i < 3; i++) {
            scanf("%d", &list[i]);
        }
        sort(list, list + 3);
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