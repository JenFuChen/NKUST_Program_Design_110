// HW4 【Finished】Build the product data and sort Date
#include <stdio.h>
#include <string.h>
int token, cnt = 0;
int settingDate = 20220328;
struct data {
    char product[100];  //產品名稱
    int ID;             //索引值
    int MFD;            //製造日期
    int EXP;            //有效日期
    float price;        //價格
};

void showData(struct data* data, int n) {
    for (int i = 0; i < cnt; i++) {
        if (data[i].price != 0) {
            if (n == 0) {
                printf("%s\n", data[i].product);
            }
            if (n == 2 &&
                data[i].EXP >= settingDate) {  // 有效日期，小於今天不輸出
                printf("%s\n", data[i].product);
            }
        }
        if (n == 5) {  // 輸出所有資料
            printf("[%d]\t%d\t%s\t%d\t%d\t$%.2f\n", i, data[i].ID,
                   data[i].product, data[i].MFD, data[i].EXP, data[i].price);
        }
    }
}

void addData(struct data* data) {
    struct data empty = {0, '\0', 0, 0, 0};  // 輸入錯誤則該項還原為此預設值
    char MFD_temp[990][11], EXP_temp[999][11];  // 有效日期、製造日期暫存器
    int temp = 0, temp2 = 0;
    scanf("%d %s %s %s %f", &data[cnt].ID, data[cnt].product, MFD_temp[cnt],
          EXP_temp[cnt], &data[cnt].price);
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) {
            continue;
        } else {
            temp = (MFD_temp[cnt][i] - 48) + temp * 10;
            temp2 = (EXP_temp[cnt][i] - 48) + temp2 * 10;
        }
    }
    token = 0;
    data[cnt].MFD = temp;
    data[cnt].EXP = temp2;
    if (data[cnt].MFD >= settingDate || data[cnt].EXP < data[cnt].MFD) {
        token = 1;  // 判斷製造日期、有效日期，錯誤則令token為1
    }
    if (token == 0) {  // 掃描索引值是否重複
        for (int i = 0; i < cnt; i++) {
            if (data[cnt].ID == data[i].ID) {
                token = 1;  // 重複則令token為1
                break;
            } else {
                token = 0;
            }
        }
    }
    if (token == 1) {
        printf("ErrorInput\n");
        data[cnt] = empty;  // 清空該次輸入
    } else if (token == 0) {
        cnt++;
    }
}

void sortMFD(struct data* data) {
    struct data temp;
    for (int i = 0; i < cnt; i++) {
        for (int j = i + 1; j < cnt; j++) {
            if (data[j].MFD < data[i].MFD) {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
            if (data[i].MFD == data[j].MFD && data[j].ID < data[i].ID) {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
    showData(data, 0);
}

void sortEXP(struct data* data) {
    struct data temp;
    for (int i = 0; i < cnt; i++) {
        for (int j = i + 1; j < cnt; j++) {
            if (data[j].EXP < data[i].EXP) {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
            if ((data[i].EXP == data[j].EXP) && (data[j].ID < data[i].ID)) {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
    showData(data, 2);
}

void sortPrice(struct data* data) {
    struct data temp;
    for (int i = 0; i < cnt; i++) {
        for (int j = i + 1; j < cnt; j++) {
            if (data[j].price < data[i].price) {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
            if ((data[j].price == data[i].price) && (data[j].ID < data[i].ID)) {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
    showData(data, 0);
}

int main() {
    struct data data[1000], temp;
    int order = 0;
    while (scanf("%d", &order)) {
        if (order == 1) {
            addData(data);
        }
        if (order == 2) {
            sortMFD(data);
        }
        if (order == 3) {
            sortEXP(data);
        }
        if (order == 4) {
            sortPrice(data);
        }
        if (order == 5) {
            break;
        }
        if (order == 6) {  //測試輸出資料
            printf("----Current data----\n");
            showData(data, 5);
            printf("--------------------\n");
        }
    }
    return 0;
}