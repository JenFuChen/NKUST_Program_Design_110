#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;
// Done  : 1018
// Result: 23 % similar to others' ! ==...

int convertToDec(char* num, int B) {
    int result = 0, getNum = 0;
    // result is result; getNum: to get the current single bit number
    // printf("===== Start To Dec Convert =====\n");
    for (int i = strlen(num) - 1; i >= 0; i--) {
        getNum = (num[i] >= 'A') ? (num[i] - 'A' + 10) : (num[i] - '0');
        result += pow(B, strlen(num) - i - 1) * getNum;
        //         |
        // recommend to replace the "pow" function but I'm lazy
    }
    // printf("===== End =====\n");
    return result;
}

void convertToOrderNum(int N, int B) {
    // printf("===== Start To Show Result =====\n");
    int getNum = 0;
    string result = "";  // use c++'s function the add the string of number
    while (N != 0) {
        getNum = (N % B <= 9) ? (N % B + '0') : (N % B + 'A' - 10);
        result += getNum;
        N /= B;
    }
    reverse(result.begin(), result.end());
    // invert the result string because it's reverse
    cout << result << endl;
    // printf("===== End =====\n");
}
int main() {
    int sum = 0;
    char order[99] = {'\0'};  // input selected function
    while (scanf("%s", order) != EOF) {
        int base, toBase = 0;
        // base: input adding number's radix
        // toBase: input showing number's radix
        char num[9999] = {'\0'};  // input num to view as string
        scanf("%s", order);
        if (strcmp(order, "Add") == 0) {  // Keep adding the input number
            scanf("%s %d", num, &base);
            sum += convertToDec(&num[0], base);
        } else if (strcmp(order, "Show") == 0) {
            scanf("%d", &toBase);
            convertToOrderNum(sum, toBase);
        } else if (strcmp(order, "Clear") == 0) {
            sum = 0;
        } else if (strcmp(order, "End") == 0) {
            break;
        }
    }

    return 0;
}