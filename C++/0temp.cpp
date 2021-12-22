#include <stdio.h>
#include <iostream>
using namespace std;
void Numchange(double A, int B) {
    int x = 0;
    if (A > 0) {
        Numchange(A * B, B);
        x = A * B;
        if (x < 10)
            printf("%d", x);
        else
            printf("%c", x + 55);
    }
}
int main() {
    int N, M;
    cin >> N >> M;
    Numchange(N, M);
}