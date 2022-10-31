#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int num = 0;
    int A_Z[26];
    int a_z[26];
    char data[1000002];
    int countA[26];  //大寫
    int countB[26];  //小寫
    gets(data);
    printf("%c\n", data[0]);
    for (int i = 2; data[i] != '\0'; i++) {
        for (int j = 65; j < 91; j++) {
            A_Z[j - 65] = j;
            if ((int)data[i] == j)
                countA[j - 65] += 1;
        }
        for (int j = 97; j < 123; j++) {
            a_z[j - 97] = j;
            if ((int)data[i] == j)
                countB[j - 97] += 1;
        }
    }
    for (int i = 0; i < 26; i++) {
        printf("%d", countA[i]);
    }
    printf("\n");
    for (int i = 0; i < 26; i++) {
        printf("%d", countB[i]);
    }
}