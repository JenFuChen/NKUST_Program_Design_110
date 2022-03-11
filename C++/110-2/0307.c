//

#include <stdio.h>
#include <string.h>
int main() {
    while (1) {
        int sum = 0, L_token = 0, R_token = 1001;
        char num2[1001] = {'\0'};
        scanf("%s", &num2);
        if (num2[0] == '-')
            break;
        //從右算到左的0
        for (int i = strlen(num2) - 1; i >= 0; i--) {
            if (num2[i] != '0') {
                R_token = i;
                break;
            }
        }

        //如果全部都沒有檢測到 就跳脫
        if (R_token == 1001)
            break;

        //從左算到右的0
        for (int j = 0; j < strlen(num2); j++) {
            if (num2[j] != '0') {
                L_token = j;
                break;
            }
        }

        for (int i = R_token; i >= L_token; i--) {
            if (num2[i] != '\0') {
                printf("%c", num2[i]);
                sum += num2[i] - '0';
            }
        }
        printf(" %d\n", sum);
    }
    return 0;
}