//十進制轉二進制
#include <stdio.h>
#include <iostream>
using namespace std;
int main() {
    //短除法
    /*for(int time = 0; time < 10; time++){
        int num, cnt, temp = 0;
        int list[8] = {0,0,0,0,0,0,0,0};//最大值為255, 八位數
        scanf("%d", &num);
        for(int i = 0 ; i < 8 ; i++){//短除法，倒序的二進制碼
            if(num != 0){
                temp = num%2;
                num = num/2;
                list[i] = temp;
            }
        }
        for(int i = 7;i>=0;i--){//倒序印出陣列值
            if(list[i] == 1 || cnt == 1){ //多餘的零不會印出，ex. 00000101 ->
    101 printf("%d",list[i]); cnt = 1;//遇到第一個１之後，後面全印
            }
        }
        cnt = 0;//判斷歸零
        printf("\n");
    }*/
    // 利用指數的方法
    int A;
    int list[1] = {1};
    float i = 7, temp = 0, num = 0;
    scanf("%d", &A);
    for (i = 7; i >= 0; i--) {
        for (int j = i; j > 0; j--) {
            list[0] = list[0] * 2;
        }
        if (temp + list[0] <= A) {
            temp = temp + list[0];
            printf("1");
        } else {
            printf("0");
        }
        list[0] = 1;
    }
    printf("\n");
    return 0;
}