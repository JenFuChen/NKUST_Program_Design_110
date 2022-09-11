// 004 
#include <iostream>
using namespace std;
int main() {
    int num;
    while (cin >> num) {
        if (num < 0)
            break;
        if ((num % 4 == 0 && num % 100 != 0) || num % 400 == 0)
            cout << "閏年" << endl;
        else
            cout << "平年" << endl;
    }
    return 0;
}