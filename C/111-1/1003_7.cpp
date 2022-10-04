#include <stdio.h>
// Haven't done
// This HW is about count the score of each player's card 

int main() {
    int playerNum = 0;        // Player Number
    int playerCard[5] = {0};  // Store Player's card (only 5 card in once)
    int counter[13] = {0};    // Counter of Each Card Num
    int suit[4] = {0};        // Store the Suit
    int checker = 0;
    for (int i = 0; i < 5; i++) {
        if ((playerCard[i] / 13) == 0) {
            suit[0] += 1;
        } else if ((playerCard[i] / 13) == 1) {
            suit[1] += 1;
        } else if ((playerCard[i] / 13) == 2) {
            suit[2] += 1;
        } else if ((playerCard[i] / 13) == 3) {
            suit[3] += 1;
        }
    }
    
    return 0;
}