#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;
int N, S, P, Q, temp, counter, countQ, countP;
void takeOdd_Even(int num) {
    P = Q = countQ = countP = counter = 0;
    while (num != 0) {
        temp = num % 10;
        num = num / 10;
        counter += 1;
        if (counter % 2 == 0) {
            Q = Q + temp * pow(10, countQ);
            countQ += 1;
        } else if (counter % 2 != 0) {
            P = P + temp * pow(10, countP);
            countP += 1;
        }
    }
    S = P - Q;
    printf("%d-%d=%d\n", P, Q, S);
    if (S >= 10) {
        takeOdd_Even(S);
    }
}
int main() {
    while (cin >> N, N > 0) {
        takeOdd_Even(N);
    }
    return 0;
}