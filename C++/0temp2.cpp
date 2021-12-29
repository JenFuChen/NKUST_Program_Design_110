#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int assume(string N, int start_count, int end_count) {
    string saveN = N;                        //保留原本的字串
    string NEW_N = N.erase(start_count, 1);  //字串砍掉index的那個數值，1個
    if (start_count == end_count) {          //遞迴停止判斷
        return 0;
    } else {
        int find = saveN[start_count];         //所要找的數值
        if (stoi(NEW_N) % (find - 48) == 0) {  //判斷是否取餘等於0
            start_count = start_count + 1;     //下個搜尋值
            find = find + 1;                   //下個find的index值
            printf("T");
            return assume(saveN, start_count, end_count);  //重新呼叫
        } else {
            start_count = start_count + 1;  //下個搜尋值
            find = find + 1;                //下個find的index值
            printf("F");
            return assume(saveN, start_count, end_count);  //重新呼叫
        }
    }
}

int main() {
    int find = 0;
    string N;
    int start_count = 0;  //開始時候
    int end_count = 0;    //結束時候
    while (1) {
        cin >> N;
        if (stoi(N) > 0 and stoi(N) < 10) {
            printf("T\n");                      //輸入個位數
        } else if (stoi(N) >= 10) {             //輸入十位數
            end_count = N.size();               //判斷長度
            assume(N, start_count, end_count);  //呼叫判斷副程式
            printf("\n");                       //換行
        } else {
            break;
        }
    }

    return 0;
}