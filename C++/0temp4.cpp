#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int num = 0;
    for (int i = 0; i < 5; i++) {
        if (i == 3) {
            continue;
        }
        printf("%d\n", i);
    }
    // while (1) {
    //     if (num % 3 == 1 && num % 5 == 3 && num % 7 == 2) {
    //         cotinue;
    //     }
    //     num++;
    // }
    return 0;
}
