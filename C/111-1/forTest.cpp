#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

char dataIn[1000];
int start[1000], ans[1000], res[1000];

const int oldBase = 10;
int newBase = 0;

void toNum() {
    int i, len = strlen(dataIn);
    start[0] = len;
    for (i = 1; i <= len; i++) {
        if (dataIn[i - 1] >= '0' && dataIn[i - 1] <= '9') {
            start[i] = dataIn[i - 1] - '0';
        }
    }
}

void converter() {
    memset(res, 0, sizeof(res));
    int y, i, j;
    while (start[0] >= 1) {
        y = 0;
        i = 1;
        ans[0] = start[0];
        while (i <= start[0]) {
            y = y * oldBase + start[i];
            ans[i++] = y / newBase;
            y %= newBase;
        }
        res[++res[0]] = y;
        i = 1;
        while ((i <= ans[0]) && (ans[i] == 0))
            i++;
        memset(start, 0, sizeof(start));
        for (j = i; j <= ans[0]; j++)
            start[++start[0]] = ans[j];
        memset(ans, 0, sizeof(ans));
    }
}
void convertToOrderNum(int N, int B) {
    int getNum = 0;
    string result = "";
    while (N != 0) {
        getNum = (N % B <= 9) ? (N % B + '0') : (N % B + 'A' - 10);
        result += getNum;
        N /= B;
    }
    reverse(result.begin(), result.end());
    cout << result;
}

int main() {
    scanf("%s %d", dataIn, &newBase);
    toNum();
    converter();
    for (int i = res[0]; i >= 1; --i) {
        convertToOrderNum(res[i], newBase);
    }
    printf("\n");
    return 0;
}