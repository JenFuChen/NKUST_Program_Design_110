#include <stdio.h>
#include <iostream>
using namespace std;
int main() {
    int list = 0;
    cin >> list;
    for (int i = 0; i < list; i++) {
        int a, b, c;
        int max, min = 0;
        int sum = 0;
        int pro = 1;
        cin >> a >> b >> c;
        if (b > c) {
            max = b;
            min = c;
        } else {
            max = c;
            min = b;
        }
        if (a == 1) {
            for (int j = min; j <= max; j++) {
                sum += j;
            }
            cout << sum << endl;
        }
        if (a == 2) {
            for (int j = min; j <= max; j++) {
                pro *= j;
            }
            cout << pro << endl;
        }
    }

    return 0;
}