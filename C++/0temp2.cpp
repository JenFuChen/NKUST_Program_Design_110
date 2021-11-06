#include <iostream>
using namespace std;
int main() {
    while (1) {
        int A;
        int list[1] = {1};
        float i = 7, temp = 0, num = 0;
        scanf("%d", &A);
        for (i = 7; i >= 0; i--) {
            for (int j = i; j > 0; j--) {
                list[0] = list[0] * 2;
            }
            if (temp + list[0] <= A) {
                temp = temp + list[0];
                printf("1");
            } else {
                printf("0");
            }
            list[0] = 1;
        }
        printf("\n");
        if (A == 0) {
            break;
        }
    }
    return 0;
}