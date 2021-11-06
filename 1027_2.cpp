//印出ASCLL碼
#include <stdio.h>
#include <iostream>
using namespace std;
int main() {
    unsigned char ch = 0;
    while (ch <= 255) {
        cout << ch << endl;
        ch = ch + 1;
    }
    return 0;
}