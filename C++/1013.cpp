//  判斷分數級別並列出
#include<iostream>
using namespace std;
int main(){
    int list[6],num1[10];
    char rank1[6]= {'S', 'A','B','C','D','E'};
    for(int i = 0; i<10;i++){
        scanf("%d",&num1[i]);
    }
    for(int i =0;i <10;i++){
        if (num1[i]==100) list[0]++;
        else if(num1[i] >= 90 && num1[i] < 100) list[1]++;
        else if(num1[i] >= 80 && num1[i] < 90) list[2]++;
        else if(num1[i] >= 70 && num1[i] < 80) list[3]++;
        else if(num1[i] >= 60 && num1[i] < 70) list[4]++;
        else if(num1[i] < 60) list[5]++;
    }
    for(int i = 0; i<6;i++){
        if(list[i]!=0){
            printf("%d%c\n",list[i],rank1[i]);
        }
    }
    return 0;
}