#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    while (1) {
        int num;
        cin >> num;
        if (num <= 0) {
            break;
        }
        for (int i = 1; i <= num; i++) {
            for (int j = 1; j <= num; j++) {
                printf("%d*%d=%d ", i, j, i * j);
            }
            printf("\n");
        }
    }
    return 0;
}