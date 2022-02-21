// C659 Finished
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char arr[100][100];
    int cnt = 0;
    while (scanf("%s", arr[cnt])) {
        if (getchar() == '\n')
            break;
        cnt += 1;
    }
    for (int x = 1; x <= cnt; x++) {
        if (x != cnt) {
            printf("%s %s ", arr[x], arr[0]);
        } else {
            printf("%s", arr[x]);
        }
    }
    return 0;
}
