#include <stdio.h>
#include <string.h>

struct student {
    char name[1000][1000];
    float average;
};

int check = 0;
void checkData(char schoolNum[][0], int cnt) {
    for (int i = 0; i < cnt; i++) {
        if (schoolNum[cnt][0] == schoolNum[i][0]) {
            check = 1;
        }
    }
}
void customSort(float average[], char name[][100], int cnt) {
    int temp = 0;
    char nameTemp[0][100];
    for (int i = 0; i < cnt; i++) {
        for (int j = i + 1; j < cnt; j++) {
            if (average[j] > average[i]) {
                temp = average[i];
                average[i] = average[j];
                average[j] = temp;
            }
        }
    }
}

int main() {
    struct student stu[1000], temp;
    char name[1000][100], schoolNumber[1000][11],
        sex[1000][6];  //姓名 學號 性別
    int chinese[1000] = {0}, english[1000] = {0}, math[1000],
        order = 0;  // 成績
    int counter = 0;
    float average[1000] = {0};
    while (1) {
        scanf("%d", &order);  // 指令
        int i = counter;
        if (order == 1) {
            scanf("%s %s %s %d %d %d", stu[i].name, schoolNumber[i], sex[i],
                  &chinese[i], &math[i], &english[i]);
            // checkData(schoolNumber[0], i);

            if (check ==
                1) {  // 驗證學號是否通過，重複則印出錯誤，且該筆資料會被覆蓋，無重複就可輸入
                printf("InputError\n");
            } else {
                stu[i].average = (chinese[i] + math[i] + english[i]) / 3;
                counter++;
            }
            // customSort(&average[0], &name[0], counter);

        } else if (order == 2) {
            for (int i = 0; i < counter; i++) {
                for (int j = i + 1; j < counter; j++) {
                    if (stu[j].average > stu[i].average) {
                        temp = stu[i];
                        stu[i] = stu[j];
                        stu[j] = temp;
                    }
                }
            }
            for (int i = 0; i < 3; i++) {
                printf("%s %f", stu[i].name, stu[i].average);
            }
        } else if (order == 3) {
            break;
        }
    }
    return 0;
}