#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Judge input number's multiple from 1 to 11
// Done  : 1107
// Result: 4 % similar to others' ! Congrats !!!!!!!
int main() {
    while (1) {
        char inputNum[1001] = {'\0'};
        int result[12] = {0};
        int eachSum = 0;
        int getNum = 0;
        scanf("%s", inputNum);
        if (inputNum[0] == '-' || inputNum[0] == '0') {
            break;
        }
        int length = strlen(inputNum) - 1;
        getchar();
        int flag = 0;
        // 2
        result[1] = 1;
        getNum = inputNum[length] - '0';
        if (getNum % 2 == 0) {
            result[2] = 1;
            flag++;
        }
        for (int i = 0; i <= length; i++) {
            eachSum = inputNum[i] - '0' + eachSum;
        }
        if (eachSum % 3 == 0) {
            result[3] = 1;
            flag++;
        }
        getNum = (inputNum[length] - '0') + ((inputNum[length - 1] - '0') * 10);
        if (getNum % 4 == 0) {
            result[4] = 1;
        }
        getNum = inputNum[length] - '0';
        if (getNum == 5 || getNum == 0) {
            if (getNum == 0) {
                result[10] = 1;
            }
            result[5] = 1;
        }
        if (flag == 2) {
            result[6] = 1;
        }

        getNum = 0;
        flag = 0;
        int oddSum = 0, evenSum = 0;
        int counter = 1;
        for (int i = length; i >= 0; i--) {
            getNum = 0;
            if (counter % 2 != 0) {
                getNum += (inputNum[i] - '0') * pow(10, flag);
                oddSum += getNum;
            } else {
                getNum += (inputNum[i] - '0') * pow(10, flag);
                evenSum += getNum;
            }
            if (flag >= 2) {
                flag = 0;
                counter++;
            } else {
                flag++;
            }
        }
        if (abs(evenSum - oddSum) % 7 == 0) {
            result[7] = 1;
        }
        getNum = 0;
        getNum = (inputNum[length] - '0') +
                 ((inputNum[length - 1] - '0') * 10) +
                 ((inputNum[length - 2] - '0') * 100);
        if (getNum % 8 == 0) {
            result[8] = 1;
        }
        eachSum = 0;
        for (int i = 0; i <= length; i++) {
            eachSum += inputNum[i] - '0';
        }
        if (eachSum % 9 == 0) {
            result[9] = 1;
        }
        oddSum = 0;
        evenSum = 0;
        flag = 0;
        for (int i = length; i >= 0; i--) {
            flag++;
            if (flag % 2 == 0) {
                evenSum += inputNum[i] - '0';
            } else {
                oddSum += inputNum[i] - '0';
            }
        }
        if (abs(evenSum - oddSum) % 11 == 0 || abs(evenSum - oddSum) == 0) {
            result[11] = 1;
        }
        for (int i = 1; i <= 11; i++) {
            if (result[i] == 1) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }
    return 0;
}