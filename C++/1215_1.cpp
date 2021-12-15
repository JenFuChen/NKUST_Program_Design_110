//使用陣列完成
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int N, S, P, Q, temp, counter;
void takeOdd_Even(int num) {
    P = Q = counter = 0;
    int num_list[50] = {0};
    string numSize;
    numSize = to_string(num);
    while (num != 0) {
        if (num != 0) {
            temp = num % 10;
            num = num / 10;
            num_list[counter] = temp;
            counter += 1;
        }
    }
    for (int i = 0; i < int(numSize.size()); i++) {
        if (i % 2 != 0) {
            Q = Q + num_list[i] * pow(10, i / 2);
        }
        if (i % 2 == 0) {
            P = P + num_list[i] * pow(10, i / 2);
        }
    }
    S = P - Q;
    printf("%d-%d=%d\n", P, Q, S);
    while (S >= 10) {
        takeOdd_Even(S);
    }
}
int main() {
    while (cin >> N, N > 0) {
        takeOdd_Even(N);
    }
    return 0;
}