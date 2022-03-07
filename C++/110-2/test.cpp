#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
    string list;  //存取字串
    while (true) {
        cin >> list;
        if (list[0] == '-')
            break;  //偵測終止條件(負數)
        int none_zero = 0;
        for (int x = 0; x < list.length(); x++) {
            int pick = list.length() - x;
            if (list[x] != '0') {  //移除0，強制轉成int類型
                list.erase(list.begin(), list.end() - pick);
                break;
            }
        }
        if (list[0] == '0')
            break;                          //偵測終止條件(全為0)
        reverse(list.begin(), list.end());  //反轉(c++可用)
        int ok = 0, total = 0;
        for (int x = 0; x < list.length(); x++) {
            if (list[x] != '0') {  //偵測是否為0
                ok = 1;
            }
            if (ok == 1) {
                total += list[x] - '0';  //加總
                cout << list[x];         //輸出結果
            }
        }
        cout << " " << total << endl;
    }
    return 0;
}