// 010
#include <iostream>
using namespace std;
int main() {
    // 大到小
    int num, temp, list[10] = {0};
    for (int i = 0; i < 10; i++) {
        scanf("%d", &list[i]);
    }
    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (list[j] > list[i]) {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        printf("%d ", list[i]);
    }
    return 0;
}