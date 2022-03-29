// HW 3 【Finished】Students' Grade and SchoolID scan
#include <stdio.h>
#include <string.h>

int check = 0;
struct student {
    // int instruction;//指令
    char name[10];  //姓名
    char ID[10];    //學號 大寫英文+9位數字
    float average;
};

int main() {
    struct student stu[1000], temp;
    char name[1000][100] = {'\0'}, schoolNumber[1000][11],
         sex[1000][6];  //姓名 學號 性別
    int chinese[1000] = {0}, english[1000] = {0}, math[1000],
        order = 0;  // 成績
    int cnt = 0;
    while (1) {
        scanf("%d", &order);  // 指令
        if (order == 1) {
            scanf("%s %s %s %d %d %d", &stu[cnt].name, schoolNumber[cnt],
                  sex[cnt], &chinese[cnt], &math[cnt], &english[cnt]);
            //判斷學號
            for (int i = 0; i < cnt; i++) {
                check = 0;
                for (int j = 0; j < 10; j++) {
                    if (schoolNumber[cnt][j] == schoolNumber[i][j]) {
                        check += 1;
                    }
                    if (check == 10) {
                        printf("ErrorInput\n");
                        for (int k = 0; k < 100; k++)
                            name[cnt][k] = '\0';
                    }
                }
            }
            if (check != 10) {
                stu[cnt].average =
                    (chinese[cnt] + math[cnt] + english[cnt]) / 3;
                cnt++;
            }
        } else if (order == 2) {
            for (int i = 0; i < cnt; i++) {
                for (int j = i + 1; j < cnt; j++) {
                    if (stu[j].average > stu[i].average) {
                        temp = stu[i];
                        stu[i] = stu[j];
                        stu[j] = temp;
                    }
                }
            }
            for (int i = 0; i < cnt; i++) {
                printf("%s\n", stu[i].name);
            }
        } else if (order == 3) {
            break;
        }
    }
    return 0;
}