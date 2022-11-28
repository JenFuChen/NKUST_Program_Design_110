// 06 最大公因數
#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    for (int i = 0; i < 3; i++) {
        int list[3] = {0, 0, 0};
        int temp = 0;
        for (int i = 0; i < 3; i++) {
            scanf("%d", &list[i]);
        }
        sort(list, list + 3);
        temp = list[0] % list[1];
        while (temp > 0) {
            list[0] = list[1];
            list[1] = temp;
            temp = list[0] % list[1];
        }
        list[0] = list[2];
        temp = list[0] % list[1];
        while (temp > 0) {
            list[0] = list[1];
            list[1] = temp;
            temp = list[0] % list[1];
        }
        printf("%d\n", list[1]);
    }
}