// 1找出最大，0則最小
#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    for (int num = 0; num < 5; num++) {
        int list[4];
        for (int j = 0; j < 4; j++) {
            scanf("%d", &list[j]);
        }
        sort(list + 1, list + 4);
        printf("%d\n", list[0] == 0 ? list[1] : list[3]);
    }
    return 0;
}