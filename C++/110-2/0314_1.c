// 大數運算 加法
#include <stdio.h>
#include <string.h>

int check = 0;  //中斷點
int total = 0;
void Reverse_Num(char rev[], char list[]) {
    int cnt = 0;
    for (int x = strlen(list) - 1; x >= 0; x--) {
        rev[cnt] = list[x];
        total += list[x] - '0';
        cnt += 1;
    }
}

void addNum(char num1[], char num2[], int sumNum[]) {
    char max[1001] = {'\0'}, min[1001] = {'\0'};
    int cnt1 = 0, cnt2 = 0;

    //將數值放入新陣列，並判斷大小數
    if (strlen(num1) > strlen(num2)) {
        for (int i = 0; i < 1001; i++) {
            if (num1[i] != '\0') {
                max[cnt1] = num1[i];
                cnt1++;
            }
            if (num2[i] != '\0') {
                min[cnt2] = num2[i];
                cnt2++;
            }
        }
    } else {
        for (int i = 0; i < 1001; i++) {
            if (num1[i] != '\0') {
                min[cnt1] = num1[i];
                cnt1++;
            }
            if (num2[i] != '\0') {
                max[cnt2] = num2[i];
                cnt2++;
            }
        }
    }
    int carry = 0, newCarry = 0, minLength = strlen(min);
    for (int i = 0; i <= strlen(max); i++, minLength--) {
        if (minLength <= 0) {
            if (i != strlen(max)) {
                sumNum[i] = (max[i] - 48 + carry) % 10;
                carry = (max[i] + carry - 48) / 10;
            } else {
                sumNum[i] = carry;
            }
        } else {
            sumNum[i] = (max[i] + min[i] - 96 + carry) % 10;
            carry = (max[i] + min[i] - 96 + carry) / 10;
            if (carry > 0 && i == strlen(max) - 1) {
                sumNum[i + 1] = carry;
            }
        }
    }
}

int main() {
    while (1) {
        char num1[1001] = {'\0'}, num2[1001] = {'\0'};
        int sumNum[1002] = {'\0'};
        scanf("%s %s", num1, num2);

        //排除負數
        if (num1[0] == '-' || num2[0] == '-') {
            break;
        }
        char R_num1[1001] = {'\0'}, R_num2[1001] = {'\0'};
        total = 0;
        Reverse_Num(R_num1, num1);
        if (total == 0)
            break;
        total = 0;
        Reverse_Num(R_num2, num2);
        if (total == 0)
            break;
        addNum(R_num1, R_num2, sumNum);
        int done = 0;
        for (int i = 1000; i >= 0; i--) {
            if (sumNum[i] != 0)
                done = 1;
            if (done == 1) {
                printf("%d", sumNum[i]);
            }
        }
        printf("\n");
    }

    return 0;
};
