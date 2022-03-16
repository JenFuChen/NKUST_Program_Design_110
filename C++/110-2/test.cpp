//大數運算 2022-03-01 陳科融
#include <memory.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char first[999] = {'\0'};
char second[999] = {'\0'};
int borrow = 10, carry = 0;
int f_size;
int s_size;
//===================<交換>=====================
void change(char change[], char list[]) {
    int size = strlen(list);
    for (int x = 0; x < size; x++) {
        change[x] = list[x];
    }
}
//===================<翻轉>=====================
void reverse(char list[], char rev[]) {
    int cnt = 0;
    for (int x = strlen(list) - 1; x >= 0; x--) {
        rev[cnt] = list[x];
        cnt += 1;
    }
}
//===================<加法>=====================
int add(char first[], char second[], int answer[]) {
    int run = 0;
    int f_size = strlen(first);
    int s_size = strlen(second);
    for (int x = 0; x < 9999; x++) {
        if (first[x] == '\0' && second[x] == '\0' && carry == 0) {
            return run;
        } else {
            if (first[x] >= '0') {
                first[x] = first[x] - '0';
            }
            if (second[x] >= '0') {
                second[x] = second[x] - '0';
            }
            answer[x] = (first[x] + second[x] + carry) % 10;
            carry = (first[x] + second[x] + carry) / 10;
            run += 1;
        }
    }
}
//==================<減法>=========================
int minus(char first[], char second[], int answer[]) {
    int run = 0;
    int f_size = strlen(first);
    int s_size = strlen(second);
    for (int x = 0; x < 999; x++) {
        if (first[x] == '\0' && second[x] == '\0') {
            return run;
        } else {
            if (first[x] >= '0') {
                first[x] = first[x] - '0';
            }
            if (second[x] >= '0') {
                second[x] = second[x] - '0';
            }
            if (first[x] >= second[x]) {
                answer[x] = first[x] - second[x];
                run += 1;
            } else if (first[x] < second[x]) {
                answer[x] = borrow - second[x] + first[x];
                int cnt = 1;
                while (first[cnt + x] == '0') {
                    first[cnt + x] += 9;
                    cnt += 1;
                }
                first[x + cnt] -= 1;
                run += 1;
            }
        }
    }
}
//===================<乘法>=====================
void multiply(char first[], char second[], int answer[]) {
    int carry = 0;
    int f_size = strlen(first);
    int s_size = strlen(second);
    int max_size = f_size + s_size;
    int** save = (int**)calloc(999, sizeof(int*));
    for (int x = 0; x < max_size; x++) {
        save[x] = (int*)calloc(999, sizeof(int));
    }
    for (int x = 0; x < f_size; x++) {
        for (int y = 0; y < s_size; y++) {
            save[x][y] = ((first[x] - '0') * (second[y] - '0'));
        }
    }
    for (int x = 0; x < f_size; x++) {
        int cnt = 0;
        for (int y = x; y < max_size; y++) {
            if (cnt == s_size) {
                continue;
            } else {
                answer[y] += save[x][cnt];
                cnt += 1;
            }
        }
    }
    for (int x = 0; x < max_size; x++) {
        if (answer[x] >= 10) {
            carry = answer[x] / 10;
            answer[x] %= 10;
            answer[x + 1] += carry;
        }
    }
    int ok = 0;
    for (int x = max_size; x >= 0; x--) {
        if (answer[x] != 0) {
            ok = 1;
        }
        if (ok == 1) {
            printf("%d", answer[x]);
        }
    }

    for (int i = 0; i < 999; i++) {
        free(save[i]);
    }
    free(save);
}
//===================<主程式>=====================
int main() {
    char operation[1];
    while (scanf("%s%s%s", first, &operation[0], second) != EOF) {
        char R_first[999] = {'\0'};
        char R_second[999] = {'\0'};
        int* answer = (int*)calloc(999, sizeof(int));
        //==================<加法動作>=====================
        if (operation[0] == '+') {
            reverse(first, R_first);
            reverse(second, R_second);
            int run = add(R_first, R_second, answer);
            for (int x = run - 1; x >= 0; x--) {
                printf("%d", answer[x]);
            }
        }
        //==================<減法動作>=====================
        if (operation[0] == '-') {
            f_size = strlen(first);
            s_size = strlen(second);
            if (f_size > s_size) {  //減數遠比被減數大
                reverse(first, R_first);
                reverse(second, R_second);
                int run = minus(R_first, R_second, answer);
                for (int x = run - 1; x >= 0; x--) {
                    printf("%d", answer[x]);
                }
            } else if (f_size == s_size) {  //減數根被減數位數相同
                int not_big = 0;
                for (int x = 0; x < f_size; x++) {
                    if (first[x] > second[x]) {
                        break;
                    } else if (first[x] == second[x]) {
                        continue;
                    } else {
                        not_big = 1;
                    }
                }
                if (not_big == 1) {  //減數比被減數小
                    reverse(first, R_first);
                    reverse(second, R_second);
                    char change_f[999] = {'\0'};
                    char change_s[999] = {'\0'};
                    change(change_f, R_second);
                    change(change_s, R_first);
                    int run = minus(change_f, change_s, answer);
                    printf("-");
                    int ok = 0;
                    for (int x = run - 1; x >= 0; x--) {
                        if (answer[x] != 0) {
                            ok = 1;
                        }
                        if (ok == 1) {
                            printf("%d", answer[x]);
                        }
                    }
                } else {  //減數大於被減數
                    reverse(first, R_first);
                    reverse(second, R_second);
                    int run = minus(R_first, R_second, answer);
                    int ok = 0;
                    for (int x = run - 1; x >= 0; x--) {
                        if (answer[x] != 0) {
                            ok = 1;
                        }
                        if (ok == 1) {
                            printf("%d", answer[x]);
                        }
                        if (x == 0 && ok == 0) {
                            printf("0");
                        }
                    }
                }
            } else if (f_size < s_size) {  //減數比被減數位數少
                reverse(first, R_first);
                reverse(second, R_second);
                char change_f[999] = {'\0'};
                char change_s[999] = {'\0'};
                change(change_f, R_second);
                change(change_s, R_first);
                int run = minus(change_f, change_s, answer);
                printf("-");
                for (int x = run - 1; x >= 0; x--) {
                    printf("%d", answer[x]);
                }
            }
        }
        //==================<乘法動作>=====================
        if (operation[0] == '*') {
            reverse(first, R_first);
            reverse(second, R_second);
            multiply(R_first, R_second, answer);
        }
        if (operation[0] == '/') {
            printf("除法沒做完");
        }
        printf("\n");
        memset(first, '\0', sizeof(char) * 999);
        memset(second, '\0', sizeof(char) * 999);
        memset(R_first, '\0', sizeof(char) * 999);
        memset(R_second, '\0', sizeof(char) * 999);
        free(answer);
    }
    return 0;
}
