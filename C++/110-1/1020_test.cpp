// 1找出最大，0則最小
#include <iostream>
using namespace std;
int main() {
    for (int num = 0; num < 5; num++) {
        int list[4];
        for (int j = 0; j < 4; j++) {
            scanf("%d", &list[j]);
        }
        for (int i = 1; i < 4; ++i) {
            for (int j = 1; j < i; ++j) {
                if (list[j] > list[i]) {
                    int temp = list[j];
                    list[j] = list[i];
                    list[i] = temp;
                }
            }
        }
        printf("%d\n", list[0] == 0 ? list[1] : list[3]);
    }
    return 0;
}