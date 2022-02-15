// 010
#include <iostream>
using namespace std;
int main() {
    int num, temp;
    cin >> num;
    while (num > 0) {
        for (int i = 0; i < num; i++) {
            int cnt = 0, check = 0;
            if (num % i == 0) {
                while (num % i == 0) {
                    cnt += 1;
                    check = 1;
                }
                if (check == 1) {
                    cout << i << "^" << cnt;
                }
                cout << "*" << i;
            }
        }
    }
    return 0;
}