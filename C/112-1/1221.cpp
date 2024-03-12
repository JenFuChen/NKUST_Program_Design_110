#include <stdio.h>
#include <stdlib.h>

#define HASHSIZE 11

int main() {
    int key[HASHSIZE] = {2, 18, 35, 0, 22, 13, 19, 9, 69, 17, 30};
    int hashtable[HASHSIZE];
    int address, count = 0;

    for (int i = 0; i < HASHSIZE; i++)
        hashtable[i] = -1;

    for (int i = 0; i < HASHSIZE; i++) {
        // 計算key[i]的位置
        address = key[i] % HASHSIZE;
        while (hashtable[address] != -1 && count < HASHSIZE) {
            address = ++(address) % HASHSIZE;
            count++;
        }
        // 把key[i]填入hashtable
        if (hashtable[address] == -1) {
            hashtable[address] = key[i];
        } else {
            continue;
        }
    }
    printf("\n> ");
    // 輸出hashtable內容
    for (int i = 0; i < HASHSIZE; i++) {
        printf("%d ", hashtable[i]);
    }
    printf("\n");

    return 0;
}
