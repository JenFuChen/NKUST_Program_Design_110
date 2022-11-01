#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Encryption the string
// Done  : 1031
// Result: 8 % similar to others' ! Congrats !
int main() {
    while (1) {
        int num = 0;
        char encryption[99][4][99] = {'\0'};
        // [n][0] store the encrypted word
        // [n][1] store the word which gonna be encrypted
        // [n][2] store the word with "," which gonna be encrypted
        // [n][3] store the word with "." which gonna be encrypted
        char input[999] = {'\0'};  // store input sentence
        char inputCopy[999] = {'\0'};
        char separateInput[999][999] = {
            '\0'};          // store each word of the sentence
        scanf("%d", &num);  // the encryption data number
        if (num <= 0)
            break;
        getchar();
        for (int i = 0; i < num; i++) {
            scanf("%s %s", encryption[i][0], encryption[i][1]);
            strcpy(encryption[i][2], encryption[i][1]);
            strcat(encryption[i][2], ",");
            strcpy(encryption[i][3], encryption[i][1]);
            strcat(encryption[i][3], ".");
            getchar();
        }
        scanf("%[^\n]%*c", input);
        strcpy(inputCopy, input);
        // cut the sentence to word and store
        int cnt = 0;
        const char* space = " ";
        char* tokenSpace;
        tokenSpace = strtok(inputCopy, space);  //
        while (tokenSpace != NULL) {
            strcpy(separateInput[cnt], tokenSpace);
            tokenSpace = strtok(NULL, space);
            cnt += 1;
        }
        char newString[99] = {'\0'};
        // printf("-- Word num: %d\n", cnt);
        // start encrypt
        int flag = 0;
        // printf("==========\n");
        // for (int i = 0; i < cnt; i++) {
        //     printf("%s\n", separateInput[i]);
        // }
        // printf("==========\n");
        for (int i = 0; i < cnt; i++) {
            flag = 0;
            for (int k = 0; k < num; k++) {
                if (strcmp(separateInput[i], encryption[k][1]) == 0) {
                    if (flag == 1)
                        continue;
                    printf("%s ", encryption[k][0]);
                    flag = 1;
                } else if (strcmp(separateInput[i], encryption[k][2]) == 0) {
                    if (flag == 1)
                        continue;
                    printf("%s, ", encryption[k][0]);
                    flag = 1;
                } else if (strcmp(separateInput[i], encryption[k][3]) == 0) {
                    if (flag == 1)
                        continue;
                    printf("%s. ", encryption[k][0]);
                    flag = 1;
                }
            }
            if (flag == 1) {
                continue;
            } else {
                printf("%s ", separateInput[i]);
            }
        }
        printf("\n");
    }
    return 0;
}