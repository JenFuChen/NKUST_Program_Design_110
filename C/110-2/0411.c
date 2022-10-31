// Finished 樂透查詢
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    while (1) {
        char customNum[99][99] = {'\0'}, winLotteryNum[99] = {'\0'};
        char *tokenCustom, *tokenWin;
        int row = 0, temp = 0, cnt = 0, counter = 0;
        int Win[5] = {0};       // Winning Lottery
        int Data[99][5] = {0};  // Customer Lottery Num
        int customWin[99][2];
        // 輸入資料
        scanf("%d", &row);  // N筆資料
        getchar();          // 排除 '\n'
        if (row <= 0) {
            break;
        }
        scanf("%[^\n]%*c", winLotteryNum);  // 中獎號碼
        temp = row;
        while (row--) {
            scanf("%[^\n]%*c", customNum[cnt]);
            cnt++;
        }
        // 拆解輸入資料並轉換至陣列
        cnt = 0;
        row = temp;
        tokenWin = strtok(winLotteryNum, ", ");
        while (tokenWin != NULL) {
            Win[cnt] = atoi(tokenWin);
            tokenWin = strtok(NULL, ", ");
            cnt++;
        }
        for (int i = 0; i < row; i++) {
            tokenCustom = strtok(customNum[i], ", ");
            for (int j = 0; j < 5; j++) {
                Data[i][j] = atoi(tokenCustom);
                tokenCustom = strtok(NULL, ", ");
            }
            // 檢查輸入號碼組是否中獎
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    if (Data[i][j] == Win[k]) {
                        counter++;
                    }
                }
            }
            customWin[i][0] = i + 1;
            customWin[i][1] = counter;
            counter = 0;
        }
        // 計算中獎號碼數量
        //         1  2  3  4  5 幾個號碼相同對應
        // token [ 0, 0, 0, 0, 0]
        int token[5] = {0}, tag = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 1; j <= 5; j++) {
                if (customWin[i][1] == j) {
                    token[j - 1] += 1;
                }
            }
        }
        // 輸出資料 有Ｎ筆資料 Ｍ個號碼相同 ; i 為 Ｎ
        for (int i = 5; i > 0; i--) {
            if (token[i - 1] > 0) {
                printf("%d %d\n", token[i - 1], i);
                tag += 1;  // 判斷是否無中獎號碼，若無則印 "None"
            }
        }
        if (tag == 0) {
            printf("None\n");
        }
    }
}