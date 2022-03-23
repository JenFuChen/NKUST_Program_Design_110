#include <stdio.h>
#include <string.h>

int check = 0;
struct student {
    // int instruction;//指令
    char name[10];  //姓名
    char ID[10];    //學號 大寫英文+9位數字
    char sex[6];
    float average;
    int chinese;
    int math;
    int english;
};

void addData() {
    struct student stu[1000], temp;
    scanf("%s %s %s %d %d %d", &stu[cnt].name, &stu[cnt].ID, &stu[cnt].sex,
          &stu[cnt].chinese, &stu[cnt].math, &stu[cnt].english);
    for (int i = 0; i < cnt; i++) {
        check = 0;
        if(stu[cnt].ID == stu[i].ID){
            printf
        }
        for (int j = 0; j < 10; j++) {
            if (schoolNumber[cnt][j] == schoolNumber[i][j]) {
                check += 1;
            }
            if (check == 10) {
                printf("InputError\n");
                for (int k = 0; k < 100; k++)
                    name[cnt][k] = '\0';
            }
        }
    }
    if (check != 10) {
        stu[cnt].average = (chinese[cnt] + math[cnt] + english[cnt]) / 3;
        cnt++;
    }
}

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
            addData();
            //判斷學號

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