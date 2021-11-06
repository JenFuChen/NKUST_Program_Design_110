//測試中...
#include <stdio.h>
#include <iostream>
using namespace std;
int main() {
    int min, temp;
    int list[20] = {97,  52,  421, 356, 1, 8,   7,   9,  21, 43,
                    541, 156, 1,   215, 1, 231, 145, 12, 78, 230};
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (list[j] > list[i]) {
                min = list[j];
                list[j] = list[i];
                list[i] = min;
            }
        }
    }
    for (int i = 0; i < 20; i++) {
        printf("%d ", list[i]);
    }
}
