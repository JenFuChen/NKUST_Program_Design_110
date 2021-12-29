#include <math.h>
#include <iostream>
using namespace std;
int main() {
    while (1) {
        int sumN = 0, midN = 0, N = 0, temp = 0, counter = 0, POW = 0,
            beforeN = 0, afterN = 0;
        scanf("%d", &N);
        if (N <= 0)
            break;
        temp = N;
        while (temp > 0) {
            //計算數字位數
            temp = temp / 10;
            counter += 1;
        }
        for (int i = counter; i > 0; i--) {
            //第幾位數做次方
            POW = pow(10, i);
            //前後拆出數字
            beforeN = N / POW;        //前
            afterN = N % (POW / 10);  //後
            //取出指定位置數字
            midN = (N - beforeN * POW - afterN) / (POW / 10);
            //前後相加變一數
            sumN = beforeN * (POW / 10) + afterN;
            if (sumN % midN == 0) {
                printf("T");
            } else {
                printf("F");
            }
        }
        printf("\n");
    }
    return 0;
}
