// A022 Finished
#include <stdio.h>

int main() {
    char arr[99] = {'\0'};
    int num = 0, cnt = 0;
    scanf("%s", &arr);
    while (arr[num] != '\0') {
        num++;
    }
    // printf("字數 = %d\n", num);
    for (int i = 0; i < num; i++) {
        // printf("%c %c\n", arr[i], arr[num - i - 1]);
        if (arr[i] == arr[num - i - 1]) {
            cnt++;
        }
    }
    if (cnt == num) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    return 0;
}
