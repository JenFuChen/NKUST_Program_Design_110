#include <math.h>
#include <iostream>
using namespace std;
int main() {
    while (1) {
        int sumN = 0, midN = 0, N = 0, temp = 0, counter = 0, beforeN = 0, afterN = 0;
        long POW = 0;
        scanf("%d", &N);
        if (N <= 0)
            break;
        temp = N;
        while (temp > 0) {
            temp = temp / 10;
            counter += 1;  //計算數字位數
        }
        for (int i = counter; i > 0; i--) {
            POW = pow(10, i);  //看第幾位數算10的次方
            //前後拆出數字
            beforeN = N / POW;        //前
            afterN = N % (POW / 10);  //後
            midN = (N - beforeN * POW - afterN) / (POW / 10);  //取出指定位置數字
            sumN = beforeN * (POW / 10) + afterN;  //前後拆掉的數組合
            printf("%c", (sumN % midN == 0 || midN == 0) ? 'T' : 'F');
        }
        printf("\n");
    }
    return 0;
}
