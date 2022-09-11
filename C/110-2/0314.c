#include <stdio.h>

int main() {
    int count = 7;
    int* countptr = &count;  // 指標 利用 countptr 間接存取 count 的資料
    // ↑星號放在指標變數之前 後面指向的位址需要加上 "&"變數 且可以設定初始值為
    // "NULL", "0"
    *countptr = 10;  //因爲countptr指向count，所以是改變count的值
    printf("%p %p", &count, countptr);  // %p 是記憶體位址
    printf("%d %d", count, *countptr);
}