#include <math.h>
#include <stdio.h>
#include <string.h>
// Judge is the prime or not
// Done: 13 % similar to others'

int reverse(int N) {
    int reverseNum = 0;
    while (N > 0) {
        reverseNum = (N % 10) + reverseNum * 10;
        N = N / 10;
    }
    return reverseNum;
}

int main() {
    while (1) {
        int input = 0;
        int reverseNum = 0;
        int judge = 0;    // 1: prime, 2: emirp, 0: None
        int checker = 0;  // confirm if there is any num can be divided
        scanf("%d", &input);
        if (input <= 1) {
            break;
        }
        reverseNum = reverse(input);
        // printf("%d\n", reverseNum);

        for (int i = 2; i < input; i++) {
            if (input % i == 0) {
                judge = 0;
                break;
            } else {
                judge = 1;
            }
        }
        if (judge == 1 && input != reverseNum) {
            for (int i = 2; i < reverseNum; i++) {
                if (reverseNum % i == 0) {
                    judge = 1;
                    break;
                } else {
                    judge = 2;
                }
            }
        }
        if (input == 2) {
            judge = 1;
        }
        switch (judge) {
            case 0:
                printf("not prime\n");
                break;
            case 1:
                printf("prime\n");
                break;
            case 2:
                printf("emirp\n");
                break;
            default:
                break;
        }
    }

    return 0;
}