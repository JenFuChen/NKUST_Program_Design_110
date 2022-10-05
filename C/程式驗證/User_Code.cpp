/*
freopen("input.txt", "r", stdin);
freopen("user_output.txt", "w", stdout);
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    freopen("data_input.txt", "r", stdin);
    freopen("user_output.txt", "w", stdout);
    /* ========== Your Code ========== */
    while (1) {
        int playerNum = 0;  // How many player
        scanf("%d", &playerNum);
        if (playerNum <= 0) {
            break;
        }
        while (playerNum--) {
            getchar();
            int playerCard[5] = {
                0};                 // Store player's card (only 5 card in once)
            int counter[13] = {0};  // Counter of each card num
            int suit[4] = {0};      // Store the card suit num
            char Suit[4][99] = {{"Spade"}, {"Heart"}, {"Diamond"}, {"Club"}};
            int cardPoint[5] = {0};
            int checker = -1, temp = 0;
            // input user card
            for (int i = 0; i < 5; i++) {
                scanf("%d", &playerCard[i]);
            }
            // detect the suit of each card
            for (int i = 0; i < 5; i++) {
                cardPoint[i] =
                    playerCard[i] % 13 == 0 ? 13 : playerCard[i] % 13;
                counter[(playerCard[i] - 1) % 13] += 1;
                if (((playerCard[i] - 1) / 13) == 0) {  // Spade
                    suit[0] += 1;
                } else if (((playerCard[i] - 1) / 13) == 1) {  // Heart
                    suit[1] += 1;
                } else if (((playerCard[i] - 1) / 13) == 2) {  // Diamond
                    suit[2] += 1;
                } else if (((playerCard[i] - 1) / 13) == 3) {  // Club
                    suit[3] += 1;
                }
            }
            // Sort the point
            for (int i = 0; i < 5; i++) {
                for (int j = i + 1; j < 5; j++) {
                    if (cardPoint[i] > cardPoint[j]) {
                        temp = cardPoint[i];
                        cardPoint[i] = cardPoint[j];
                        cardPoint[j] = temp;
                    }
                }
            }
            temp = 0;
            // Output the result to view
            // printf("|黑桃 %d| 紅心 %d| 方塊 %d| 梅花 %d|\n", suit[0],
            // suit[1], suit[2],
            //        suit[3]);

            // for (int i = 0; i < 13; i++) {
            //     printf("%d ", counter[i]);
            // }
            // printf("\n");
            int special[5] = {1, 10, 11, 12, 13};
            for (int i = 0; i < 5; i++) {
                if (cardPoint[i] == special[i]) {
                    temp += 1;
                }
            }
            if (temp == 5) {
                checker = 3;
            }
            temp = 0;
            for (int i = 0; i < 4; i++) {
                if (suit[i] == 5) {
                    for (int j = 0; j < 5; j++) {
                        if ((cardPoint[j] == cardPoint[j + 1] - 1) && j != 4) {
                            temp += 1;
                        }
                    }
                }
            }
            if (temp == 4) {
                checker = 0;  // 同花順
            } else {
                temp = 0;
                for (int j = 0; j < 5; j++) {
                    if (j != 4 && (cardPoint[j] == cardPoint[j + 1] - 1)) {
                        temp += 1;
                    }
                }
                if (temp == 4) {
                    checker = 3;  //順子
                }
            }
            if (checker == -1) {
                for (int i = 0; i < 13; i++) {
                    if (counter[i] == 4) {  // 四條
                        checker = 1;
                    } else if (counter[i] == 3) {
                        for (int j = i + 1; j < 13; j++) {
                            if (counter[j] == 2) {
                                checker = 2;  // 葫蘆
                                break;
                            } else {
                                checker = 4;  //三條
                            }
                        }
                    } else if (counter[i] == 2 && checker == -1) {
                        for (int j = i + 1; j < 13; j++) {
                            if (counter[j] == 3) {
                                checker = 2;
                                break;
                            } else if (counter[j] == 2) {
                                checker = 5;  // 兩對
                                break;
                            } else {
                                checker = 6;  //一對
                            }
                        }
                    }
                }
            }

            if (checker == -1) {
                checker = 7;  // 雜牌
            }
            printf("%d\n", 7 - checker);
        }
    }
    /* ========== End ========== */
    return 0;
}