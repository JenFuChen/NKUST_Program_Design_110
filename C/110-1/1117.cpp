#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int data[50];
    int N;
    while (1) {
        cin >> N;
        if (N <= 0) {
            break;
        } else if (N > 0) {
            for (int i = 0; i <= N; i++) {
                scanf("%d", &data[i]);
            }
            sort(data + 1, data + N + 1);
            if (data[0] == 1) {
                printf("%d ", data[1]);
                for (int j = 0; j < data[1]; j++) {
                    printf("*");
                }
                printf("\n");
            }
            if (data[0] == 2) {
                printf("%d ", data[N]);
                for (int j = 0; j < data[N]; j++) {
                    printf("*");
                }
                printf("\n");
            }
        }
    }
    return 0;
}