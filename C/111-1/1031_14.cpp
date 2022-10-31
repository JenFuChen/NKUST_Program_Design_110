#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Encryption the word by displacement
// Done  : 1031
// Result: 38 % similar to others' ! ==... !!!!!!
int main() {
    char dictionary[52] = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char input[99] = {'\0'};
    int displacement = 0;
    int encryption = 0;
    while (1) {
        scanf("%d", &displacement);
        if (abs(displacement) > 51) {
            break;
        }
        scanf("%s", input);
        for (int i = 0; i < strlen(input); i++) {
            if (input[i] >= 'A' && input[i] <= 'Z') {  // A to Z
                encryption = input[i] - 'A' + 26 + displacement;
                encryption = (encryption > 51) ? encryption - 52 : encryption;
                encryption = (encryption < 0) ? 52 + encryption : encryption;
                printf("%c", dictionary[encryption]);
            } else if (input[i] >= 'a' && input[i] <= 'z') {
                encryption = input[i] - 'a' + displacement;
                encryption = (encryption > 51) ? encryption - 52 : encryption;
                encryption = (encryption < 0) ? 52 + encryption : encryption;
                printf("%c", dictionary[encryption]);
            } else {
                printf("%c", input[i]);
            }
        }
        printf("\n");
    }
    return 0;
}