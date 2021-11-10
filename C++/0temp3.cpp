#include <stdio.h>
#include <iostream>
using namespace std;
int main() {
    int grade = 50;
    if(grade<60)
        printf("A");
    else
        if(grade>70)
            printf("B");
        else
            printf("C");
            printf("D");
    printf("E");
}