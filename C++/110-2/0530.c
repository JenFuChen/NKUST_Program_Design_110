#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

//-----表格結構-----//
typedef struct {
    char nameTable[99];        // 該表格名稱
    char dataType[200][99];    // 該欄資料型態 INTEGER、FLOATING或STRING
    char dataName[200][99];    // 該欄資料名稱
    char data[200][200][999];  // 儲存資料
    int row;                   // 列數
    int column;                // 欄數
} table;

char command[99][99];             // 輸入指令
int recordNum = 0, inputNum = 0;  // 整體表格數量、輸入資料數量

// void insert(table* Table) {
//     int whichTable, checkTable, insertNum, cnt = 0;
//     // 尋找指定表格、確認是否找到
//     insertNum = inputNum - 3;  //輸入資料指令筆數，減三是因為前三位為其他指令
//     // 尋找指定表格
//     for (int i = 0; i < recordNum; i++) {
//         if (strcmp(Table[i].nameTable, command[2]) == 0) {
//             whichTable = i;
//             checkTable = 0;
//             break;
//         } else {
//             checkTable = 1;
//         }
//     }

//     if (insertNum != Table[whichTable].column) {
//         // 輸入欄位數量與該表格欄位數不符
//         printf("Number of fields is not consistent\n");
//     }
//     if (checkTable == 1) {
//         printf("Table does not exist\n");
//     }
//     if (checkTable == 0 && insertNum == Table[whichTable].column) {
//         for (int i = 0; i < Table[whichTable].column; i++) {
//             strcpy(Table[whichTable].data[Table[whichTable].row][i],
//                    command[i + 3]);
//         }
//         Table[whichTable].row += 1;
//     }
// }

// void showTableContent(table* Table) {
//     int whichTable = 0;  // 指定表格
//     for (int i = 0; i < recordNum; i++) {
//         if (strcmp(Table[i].nameTable, command[1]) == 0) {
//             whichTable = i;
//             break;
//         }
//     }
//     // 顯示欄位名稱
//     for (int i = 0; i < Table[whichTable].column; i++) {
//         printf("%s\t", Table[whichTable].dataName[i]);
//     }
//     printf("\n");
//     // 輸出資料
//     for (int i = 0; i < Table[whichTable].row; i++) {
//         for (int j = 0; j < Table[whichTable].column; j++) {
//             if (strcmp(Table[whichTable].dataType[j], "STRING") == 0) {
//                 printf("%s\t", Table[whichTable].data[i][j]);
//             } else if (strcmp(Table[whichTable].dataType[j], "FLOATING") ==
//             0) {
//                 printf("%.1f\t", atof(Table[whichTable].data[i][j]));
//             } else if (strcmp(Table[whichTable].dataType[j], "INTEGER") == 0)
//             {
//                 printf("%d\t", atoi(Table[whichTable].data[i][j]));
//             }
//         }
//         printf("\n");
//     }
// }

int main() {
    table* Table = (table*)malloc(MAX * sizeof(Table));
    // Table Table[50];
    int cnt = 0;
    recordNum = 0;
    while (1) {
        char input[999] = {'\0'};
        int value;
        cnt = 0;
        //處理輸入資料
        scanf("%[^\n]%*c", input);
        char* cut = strtok(input, " ");
        while (cut != NULL) {
            strcpy(command[cnt++], cut);
            cut = strtok(NULL, " ");
        }
        /*char** command = (char**)malloc(200 * sizeof(char*));
        for (int x = 0; x < 200; x++) {
            command[x] = (char*)malloc(999 * sizeof(char));
        }
        char* d = " ";
        char* pick = strtok(input, d);
        int data_cnt = 0;
        while (pick != NULL) {
            strcpy(command[data_cnt++], pick);
            pick = strtok(NULL, d);
        }*/
        inputNum = cnt;  // 輸入指令總個數
        // createTable TableName N <FieldName1> <FieldType1> .. <FieldNameN>
        // <FieldTypeN>
        if (strcmp(command[0], "createTable") == 0) {  // 建立表格

            int duplicatedName = 0, typeError = 0, duplicatedFiledName = 0,
                numOfData = 0;  // 名稱重複、型別錯誤、欄位名稱重複、數量錯誤
            int value = atoi(command[2]);  // 欄位數量
            int cntType = 4;  // 欄位型別起始位置（對應command）
            int cntName = 3;  // 欄位名稱起始位置（對應command）
            int cntColumn = 3;
            char tempName[99][99];  // 暫存欄位名稱，用以比較欄位名稱是否衝突
            if (inputNum != (value * 2 + 3)) {
                numOfData = 1;  // 輸入指令欄位數與指定數量不符
            }
            for (int i = 0; i < recordNum; i++) {  // 確認表格名稱
                if (strcmp(Table[i].nameTable, command[1]) == 0) {
                    duplicatedName = 1;
                    break;
                }
            }
            for (int i = 4; i < inputNum; i += 2) {  // 確認欄位型別
                if ((strcmp(command[i], "INTEGER") == 0 ||
                     (strcmp(command[i], "FLOATING") == 0) ||
                     (strcmp(command[i], "STRING") == 0))) {
                    typeError = 0;
                } else {
                    typeError = 1;
                    break;
                }
            }
            for (int i = 0; i < value; i += 1) {  // 複製輸入指令欄位名稱
                strcpy(tempName[i], command[cntColumn]);
                cntColumn += 2;
            }
            for (int i = 0; i < value; i += 1) {  // 確認欄位名稱
                for (int j = i + 1; j < value; j++) {
                    if (strcmp(tempName[i], tempName[j]) == 0) {
                        duplicatedFiledName = 1;
                        break;
                    }
                }
            }

            // printf("data Num = %d  value = %d\n", numOfData, value);
            if (duplicatedName == 1) {
                printf("Table name duplicated\n");
            } else if (numOfData == 1) {
                printf("Incorrect command\n");
            } else if (typeError == 1) {
                printf("Field type incorrect\n");
            } else if (duplicatedFiledName == 1) {
                printf("Field name duplicated\n");
            } else {
                printf("( %d, %d)\n", value, recordNum);
                printf("( %d, %d)\n", cntName, cntType);
                for (int i = 0; i < inputNum; i++) {
                    printf("%s ", command[i]);
                }
                printf("\n");
                // strcpy(Table[recordNum].nameTable, command[1]);
                // for (int i = 0; i < value; i += 1) {  // 複製欄位名稱、型別
                //     strcpy(Table[recordNum].dataName[i], command[cntName]);
                //     strcpy(Table[recordNum].dataType[i], command[cntType]);
                //     cntName += 2;
                //     cntType += 2;
                // }
                // Table[recordNum].column = value;  // 設定欄數 （直的）
                // Table[recordNum].row = 0;         // 設定列數 （橫的）
                // // // printf("Successful\n-------------\n");
                // recordNum += 1;
            }
        } else if (strcmp(command[0], "showTableList") == 0) {
            for (int i = 0; i < recordNum; i++) {
                printf("%s [", Table[i].nameTable);
                for (int j = 0; j < Table[i].column; j++) {
                    if (j != (Table[i].column - 1)) {
                        printf("(%s, %s) ", Table[i].dataName[j],
                               Table[i].dataType[j]);
                    } else {
                        printf("(%s, %s)", Table[i].dataName[j],
                               Table[i].dataType[j]);
                    }
                }
                printf("]\n");
            }
        } else if (strcmp(command[0], "insert") == 0) {
            // insert(Table);
        } else if (strcmp(command[0], "showTableContent") == 0) {
            // showTableContent(Table);
        } else if (strcmp(command[0], "select") == 0) {
            // Building
        } else if (strcmp(command[0], "exit") == 0) {
            break;
        } else {
            printf("Incorrect command\n");
        }
        memset(command, '\0', 99 * 99 * sizeof(char));  // 清除指令
    }

    return 0;
}