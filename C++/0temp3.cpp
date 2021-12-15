#include <stdio.h>
#include <iostream>
using namespace std;
int c = 0;
void test(int a, int b) {
    c = a + b;
    printf("C= %d", c);
}
int main() {
    int num, num2;
    scanf("%d %d", &num, &num2);
    test(num, num2);
}