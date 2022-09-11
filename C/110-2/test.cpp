#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int main() {
    /*
     int cnt = 8;
     for (int i = 0; i < 7; i++) {
         for (int j = 0; j < i; j++) {
             printf(" ");
         }
         for (int j = 0; j < cnt; j++) {
             printf("*");
         }

         cnt -= 2;
         printf("\n");

     }*/
    /*
    int people = 0, money = 0;
    scanf("請輸入", "%d", &people);
    money = people * 398 - (people % 3) * 398;
    printf("總金額為：%d\n", money);*/
    // char input[99] = {'\0'};
    int cnt = 0;
    string input;
    getline(cin, input);
    if (input.size() != 0) {
        cnt += 1;
    }
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == ' ') {
            cnt += 1;
        }
        if (input[i] == '.') {
            break;
        }
    }
    printf("總共有 %d 個英文單字\n", cnt);
    return 0;
}