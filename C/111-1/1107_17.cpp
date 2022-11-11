#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

// any radix multiple
// Done  : 1107
// Result: 12 % similar to others' ! 
void convertToOrderNum(int N, int B) {
    // printf("===== Start To Show Result =====\n");
    int getNum = 0;
    string result = "";  // use c++'s function the add the string of number
    while (N != 0) {
        getNum = (N % B <= 9) ? (N % B + '0') : (N % B + 'A' - 10);
        result += getNum;
        N /= B;
    }
    reverse(result.begin(), result.end());
    // invert the result string because it's reverse
    cout << result;
    // printf("===== End =====\n");
}
int main() {
    int N = 0;
    int result = 0;
    while (1) {
        scanf("%d", &N);
        if (N <= 1 || N > 36) {
            break;
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                result = i * j;
                convertToOrderNum(i, N);
                printf("*");
                convertToOrderNum(j, N);
                printf("=");
                convertToOrderNum(result, N);
                printf(" ");
            }
            printf("\n");
        }
    }

    return 0;
}