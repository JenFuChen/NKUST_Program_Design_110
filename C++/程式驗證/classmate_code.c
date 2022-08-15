// UVa 11219 Done
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("classmates_output.txt", "w", stdout);
    FILE* fptr;
    fptr = fopen("classmates_output.txt", "w");
    char input[99] = {'\0'};
    char currentDate[4][99];
    char birthDate[4][99];
    char* cut;
    int N = 0, cnt = 0, caseCnt = 1, check = 0, age = 0;
    int nowDD, nowMM, nowYY, birthDD, birthMM, birthYY;
    // 輸入 N 筆
    scanf("%d", &N);
    // scanf("%d", &N);
    while (N--) {
        //取得輸入資料
        getchar();  // 取得空白行
        check = 0;
        age = 0;
        for (int i = 0; i < 2; i++) {
            cnt = 0;
            // fscanf(in, "%d", &N);
            scanf("%s", input);
            //切割輸入並存至不同陣列
            cut = strtok(input, "/");
            while (cut != NULL) {
                if (i == 0) {
                    strcpy(currentDate[cnt++], cut);
                    cut = strtok(NULL, "/");
                } else if (i == 1) {
                    strcpy(birthDate[cnt++], cut);
                    cut = strtok(NULL, "/");
                }
            }
        }
        // 整理資料
        nowDD = atoi(currentDate[0]);
        nowMM = atoi(currentDate[1]);
        nowYY = atoi(currentDate[2]);
        birthDD = atoi(birthDate[0]);
        birthMM = atoi(birthDate[1]);
        birthYY = atoi(birthDate[2]);
        // 輸出
        if (nowYY >= birthYY) {
            if (nowYY > birthYY) {
                if (nowMM >= birthMM) {
                    if (nowMM > birthMM) {
                        age = nowYY - birthYY;
                    } else {
                        if (nowDD >= birthDD) {
                            age = nowYY - birthYY;
                        } else {
                            age = nowYY - birthYY - 1;
                        }
                    }
                } else {
                    age = nowYY - birthYY - 1;
                }
            } else if (nowYY == birthYY) {
                if (nowMM >= birthMM) {
                    if (nowMM > birthMM) {
                        age = 0;
                    } else {
                        if (nowDD >= birthDD) {
                            age = 0;
                        } else {
                            check = 1;
                        }
                    }
                } else {
                    check = 1;
                }
            }
        } else {
            check = 1;
        }
        if (age > 130) {
            check = 2;
        }
        switch (check) {
            case 1:
                fprintf(fptr, "Case #%d: Invalid birth date\n", caseCnt);
                // printf("Case #%d: Invalid birth date\n", caseCnt);
                break;
            case 2:
                fprintf(fptr, "Case #%d: Check birth date\n", caseCnt);
                // printf("Case #%d: Check birth date\n", caseCnt);
                break;
            default:
                fprintf(fptr, "Case #%d: %d\n", caseCnt, age);
                // printf("Case #%d: %d\n", caseCnt, age);
                break;
        }
        caseCnt++;
    }
    fclose(fptr);
    return 0;
}