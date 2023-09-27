/*
    ｜0921 Practice 1｜
    Author: JEN-FU CHEN, C110152319
    Build Date: 2023.09.21
    Description: Array application
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int strcomp(char* a, char* b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] == b[i])
            i++;
        else if (a[i] > b[i])
            return 1;
        else
            return -1;
    }
    if (a[i] != '\0' && b[i] != '\0')
        return 0;
    else if (a[i] != '\0')
        return 1;
    else
        return -1;
}

int main() {
    char *a, *b, *c;
    a = (char*)malloc(sizeof(char) * 80);  // Contain 80 character
    b = (char*)malloc(sizeof(char) * 80);

    scanf("%s", a);
    scanf("%s", b);

    c = strcomp(a, b) == 1 ? a : b;

    printf("%s", c);
}