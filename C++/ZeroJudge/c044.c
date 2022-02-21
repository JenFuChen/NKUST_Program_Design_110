#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int line, cnt = 0;
    scanf("%d", &line);
    char list[line][99];
    while (line--) {
        scanf("%[^\n]%*c", &list[cnt]);
        cnt++;
    }
    puts(list[0]);
    int letter[26] = {0};
    for (int i = 0; i < cnt; i++) {
        for (int x = 0; x < strlen(list[i]); x++) {
            // 65-90 97-122
            for (int y = 65; y < 91; y++) {
                if ((int)list[i][x] == y) {
                    letter[y - 65]++;
                }
            }
            for (int y = 97; y < 123; y++) {
                if ((int)list[i][x] == y) {
                    letter[y - 97]++;
                }
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        printf("%d ", letter[i]);
    }
    printf("\n");
    return 0;
}