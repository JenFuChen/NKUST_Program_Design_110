#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

//-----表格結構-----//
typedef struct {
    char nameTable[99];     // 該表格名稱
    char dataType[99][99];  // 儲存資料型態 INTEGER、FLOATING或STRING
    char dataName[99][99];  // 儲存該欄資料名稱
    char data[99][6][99];   // 儲存資料
    int row;                // 列
    int column;             // 欄
} table;

char command[99][99];             // 輸入指令
int recordNum = 0, inputNum = 0;  // 整體表格數量、輸入資料數量

int checkData(table* Table, int type, int value) {
    char tempName[100][10];  // 暫存欄位名稱，用以比較欄位名稱是否衝突
    int cnt = 0, check = 0;
    if (type == 1) {  // 確認表格名稱
        for (int i = 0; i < recordNum; i++) {
            if (strcmp(Table[i].nameTable, command[1]) == 0) {
                check = 1;
                break;
            }
        }
    }
    if (type == 2) {  // 確認欄位型別
        for (int i = 4; i < inputNum; i += 2) {
            if ((strcmp(command[i], "INTEGER") == 0 ||
                 (strcmp(command[i], "FLOATING") == 0) ||
                 (strcmp(command[i], "STRING") == 0))) {
                check = 0;
            } else {
                check = 1;
                break;
            }
        }
    }
    if (type == 3) {  // 確認欄位名稱
        cnt = 3;
        for (int i = 0; i < value; i += 1) {
            strcpy(tempName[i], command[cnt]);
            cnt += 2;
        }
        for (int i = 0; i < value; i += 1) {
            for (int j = i + 1; j < value; j++) {
                if (strcmp(tempName[i], tempName[j]) == 0) {
                    check = 1;
                    break;
                }
            }
        }
    }
    return check;
}

void createTable(table* Table) {
    // createTable TableName dataNum FieldName FieldType
    int duplicatedName = 0, typeError = 0, duplicatedFiledName = 0,
        numOfData = 0;  // 名稱重複、型別錯誤、欄位名稱重複、欄位數量
    int value = atoi(command[2]);  // 欄位數量
    int cntType = 4;  // 欄位型別起始位置（對應command）
    int cntName = 3;  // 欄位名稱起始位置（對應command）
    if (checkData(Table, 1, value) == 1) {
        duplicatedName = 1;
    }
    if (checkData(Table, 2, value) == 1) {
        typeError = 1;
    }
    if (checkData(Table, 3, value) == 1) {
        duplicatedFiledName = 1;
    }
    if (inputNum != (value * 2 + 3)) {
        numOfData = 1;
    }
    // printf("data Num = %d  value = %d\n", numOfData, value);
    if (duplicatedName == 1) {
        printf("Table name duplicated\n");
    } else if (typeError == 1) {
        printf("Field type incorrect\n");
    } else if (duplicatedFiledName == 1) {
        printf("Field name duplicated\n");
    } else if (numOfData == 1) {
        printf("Incorrect command\n");
    } else {
        printf("( %d, %d)\n", value, recordNum);

        Table[recordNum].column = value;  // 設定欄數 （直的）
        Table[recordNum].row = 0;         // 設定列數 （橫的）
        strcpy(Table[recordNum].nameTable, command[1]);

        // 複製欄位名稱、型別
        for (int i = 0; i < value; i += 1) {
            strcpy(Table[recordNum].dataName[i], command[cntName]);
            strcpy(Table[recordNum].dataType[i], command[cntType]);
            cntName += 2;
            cntType += 2;
        }
        // printf("Successful\n-------------\n");
        recordNum += 1;
    }
}

void showTableList(table* Table) {
    for (int i = 0; i < recordNum; i++) {
        printf("%s [", Table[i].nameTable);
        for (int j = 0; j < Table[i].column; j++) {
            if (j != (Table[i].column - 1)) {
                printf("(%s, %s) ", Table[i].dataName[j], Table[i].dataType[j]);
            } else {
                printf("(%s, %s)", Table[i].dataName[j], Table[i].dataType[j]);
            }
        }
        printf("]\n");
    }
}

void insert(table* Table) {
    int whichTable, checkTable, insertNum, cnt = 0;
    // 尋找指定表格、確認是否找到
    insertNum = inputNum - 3;  //輸入資料指令筆數，減三是因為前三位為其他指令
    // 尋找指定表格
    for (int i = 0; i < recordNum; i++) {
        if (strcmp(Table[i].nameTable, command[2]) == 0) {
            whichTable = i;
            checkTable = 0;
            break;
        } else {
            checkTable = 1;
        }
    }

    if (insertNum != Table[whichTable].column) {
        // 輸入欄位數量與該表格欄位數不符
        printf("Number of fields is not consistent\n");
    }
    if (checkTable == 1) {
        printf("Table does not exist\n");
    }
    if (checkTable == 0 && insertNum == Table[whichTable].column) {
        for (int i = 0; i < Table[whichTable].column; i++) {
            strcpy(Table[whichTable].data[Table[whichTable].row][i],
                   command[i + 3]);
        }
        Table[whichTable].row += 1;
    }
}

void showTableContent(table* Table) {
    int whichTable = 0;  // 指定表格
    for (int i = 0; i < recordNum; i++) {
        if (strcmp(Table[i].nameTable, command[1]) == 0) {
            whichTable = i;
            break;
        }
    }
    // 顯示欄位名稱
    for (int i = 0; i < Table[whichTable].column; i++) {
        printf("%s\t", Table[whichTable].dataName[i]);
    }
    printf("\n");
    // 輸出資料
    for (int i = 0; i < Table[whichTable].row; i++) {
        for (int j = 0; j < Table[whichTable].column; j++) {
            if (strcmp(Table[whichTable].dataType[j], "STRING") == 0) {
                printf("%s\t", Table[whichTable].data[i][j]);
            } else if (strcmp(Table[whichTable].dataType[j], "FLOATING") == 0) {
                printf("%.1f\t", atof(Table[whichTable].data[i][j]));
            } else if (strcmp(Table[whichTable].dataType[j], "INTEGER") == 0) {
                printf("%d\t", atoi(Table[whichTable].data[i][j]));
            }
        }
        printf("\n");
    }
}

int main() {
    table* Table = (table*)malloc(100 * sizeof(Table));
    // Table Table[50];
    int cnt = 0;
    while (1) {
        char input[999] = {'\0'};
        char* inputPtr;
        int value;
        cnt = 0;
        //處理輸入資料
        scanf("%[^\n]%*c", input);
        inputPtr = strtok(input, " ");
        while (inputPtr != NULL) {
            strcpy(command[cnt], inputPtr);
            inputPtr = strtok(NULL, " ");
            cnt += 1;
        }
        inputNum = cnt;  //輸入指令總個數

        // for (int i = 0; i < cnt; i++) {
        //     printf("%s\n", command[i]);
        // }

        if (strcmp(command[0], "createTable") == 0) {
            createTable(Table);
        } else if (strcmp(command[0], "showTableList") == 0) {
            showTableList(Table);
        } else if (strcmp(command[0], "insert") == 0) {
            insert(Table);
        } else if (strcmp(command[0], "showTableContent") == 0) {
            showTableContent(Table);
        } else if (strcmp(command[0], "select") == 0) {
            // Building
        } else if (strcmp(command[0], "exit") == 0) {
            break;
        } else {
            printf("Incorrect command\n");
        }
        memset(command, '\0', 99 * 99 * sizeof(char));  // 清除指令
        free(command);
    }

    return 0;
}