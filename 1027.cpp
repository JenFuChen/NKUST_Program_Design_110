//作業 ０４ ． 輸入三組資料，每筆有九個數值，排序後總和並印出中間值
#include <stdio.h>
#include <iostream>
using namespace std;
int main() {
    for (int num = 0; num < 3; num++) {
        int min, sum = 0;
        int list[9];
        for (int i = 0; i < 9; i++) {
            scanf("%d", &list[i]);
        }
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (list[j] > list[i]) {
                    min = list[j];
                    list[j] = list[i];
                    list[i] = min;
                }
            }
        }
        for (int i = 0; i < 9; i++) {
            sum = sum + list[i];
        }
        printf("%d %d\n", sum, list[4]);
    }
    return 0;
}
