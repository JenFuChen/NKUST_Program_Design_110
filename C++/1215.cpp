#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;
int N, S, P, Q, temp, counter, countQ, countP = 0;
void takeOdd_Even(int N) {
    P = Q = countQ = countP = 0;
    while (N != 0) {
        if (N != 0) {
            temp = N % 10;
            N = N / 10;
            // printf("temp = %d\n", temp);
            counter += 1;
        }
        if (counter % 2 == 0) {
            Q = Q + temp * pow(10, countQ);
            countQ += 1;
            // printf("Q = %d\n", Q);
        } else if (counter % 2 != 0) {
            P = P + temp * pow(10, countP);
            countP += 1;
            // printf("P = %d\n", P);
        }
    }
    S = P - Q;
    printf("%d-%d=%d\n", P, Q, S);
}
int main() {
    cin >> N;
    S = 0;
    takeOdd_Even(N);
    while (S >= 10) {
        takeOdd_Even(S);
    }
    return 0;
}