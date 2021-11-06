//  判斷分數級別並列出
#include<iostream>
using namespace std;
int main(){
    int list[6], num1[10];
    int score[5] = {100,90,80,70,60};
    char rank1[6] = {'S','A','B','C','D','E'};
    for(int i = 0; i < 10 ; i++){ 
        scanf("%d",&num1[i]);
        if(num1[i] == score[0]) list[0]++;
        for(int j = 1 ; j < 5 ; j++){
            if(num1[i] >= score[j] && num1[i] < score[j-1]) list[j]++;
        }
        if(num1[i] < score[4]) list[5]++;
    }
    for(int i = 0 ; i < 6 ; i++){
        if(list[i] != 0){
            printf("%d%c\n",list[i],rank1[i]);
        }
    }
    return 0;
}