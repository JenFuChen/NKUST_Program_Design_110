//特殊九九乘法
#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    for(int k = 1; k<18;k+=2){
        for(int i=1; i <10;i++){
            for(int j = 1; j<10; j++){
                if((i+j)==k){
                    printf("%dX%d=%d\n",i,j,i*j);
                }
            }
        }
    }
    for (int i=1;i<10;i++){
        if(i%2 != 0){
            for(int j=1;j<10;j+=2){
                printf("%dX%d=%d\n",i,j,i*j);
            }
        }
        if(i%2==0){
            for(int k=2;k<10;k+=2){
                printf("%dX%d=%d\n",i,k,i*k);
            }
        }
    }
    return 0;
}