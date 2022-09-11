#include <stdio.h>
#include <string.h>
int cnt = 0;

struct data {
    int ID;
    char name[999];
    char address[999];
    char birth[11];
};

void addData(struct data* data) {
    scanf("%d %s %s %s", &data[cnt].ID, data[cnt].name, data[cnt].address,
          data[cnt].birth);
    cnt++;
}

void updateData(struct data* data) {
    struct data temp;
    int recordSpot = 0, token = 1;
    scanf("%d %s %s %s", &temp.ID, temp.name, temp.address, temp.birth);
    for (int i = 0; i < cnt; i++) {
        if (data[i].ID == temp.ID) {
            recordSpot = i;
            token = 0;
            break;
        }
    }
    if (token == 1) {
        printf("None\n");
    } else { // 用 string copy 更新資料
        strcpy(data[recordSpot].name, temp.name);
        strcpy(data[recordSpot].address, temp.address);
        strcpy(data[recordSpot].birth, temp.birth);
    }
}

void deleteData(struct data* data) {
    int deleteID = 0, token = 1;
    struct data empty = {0, '\0', '\0', '\0'};
    scanf("%d", &deleteID);
    for (int i = 0; i < cnt; i++) {
        if (data[i].ID == deleteID) {
            data[i] = empty;
            token = 0;
            break;
        }
    }
    if (token == 1) {
        printf("None\n");
    }
}

void searchData(struct data* data) {
    int searchID, token = 1;
    scanf("%d", &searchID);
    for (int i = 0; i < cnt; i++) {
        if (data[i].ID == searchID) {
            printf("%s %s %s\n", data[i].name, data[i].address, data[i].birth);
            token = 0;
            break;
        }
    }
    if (token == 1) {
        printf("None\n");
    }
}

int main() {
    struct data data[1000], temp;
    int breakPoint = 0;
    char order = ' ';
    while (breakPoint == 0) {
        scanf("%c", &order);
        switch (order) {
            case '@':
                addData(data);
                break;
            case '#':
                deleteData(data);
                break;
            case '!':
                updateData(data);
                break;
            case '$':
                searchData(data);
                break;
            case '*':
                breakPoint = 1;
                break;
            default:
                break;
        }
    }
    return 0;
}