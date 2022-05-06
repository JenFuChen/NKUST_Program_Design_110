#include <stdio.h>
#include <string.h>

void replace(char* sentence, char* goal, char* newWord, int cnt) {
    int newWLen = strlen(newWord);
    char answer[9999] = {'\0'};
    strcat(answer, *(sentence + 0));  // this is a pen or is a apple.is a pen'\0
    if (strstr()) {
        sentence + 5;
        sentence = '\0';
        strcat(answer, newWord);
    } else {
        strcat(answer, newWord);
    }
}

void insert() {
    

}   
int main() {
    int order = 0, cnt = 0;
    char* tokenStr;                    // 切句子的指標token
    char data[999] = {'\0'};           // 使用者輸入的
    char sentence[999][999] = {'\0'};  // 以"."切斷後存到新的
    char goal[999] = {'\0'}, newWord[999] = {'\0'};  //目標單字 替換單字
    scanf("%[^\n]%*c", data);                        // 輸入
    tokenStr = strtok(data, ".");                    //
    while (tokenStr != NULL) {
        strcpy(sentence[cnt], tokenStr);
        tokenStr = strtok(NULL, ".");
        cnt += 1;
    }
    for (int x = 0; x < cnt; x++) {
        printf("%s\n", sentence[x]);
    }
    return 0;
}