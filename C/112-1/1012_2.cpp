// 1012

// Author: 四子三丙 陳人輔 C110152319
// Class : 資料結構
// Description : 練習二分法搜尋、選擇排序（非泡泡）

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 101
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
#define COMPARE(x, y) ((x < y) ? -1 : ((x == y) ? 0 : 1))

void sort(int*, int n);

int BinarySearch(int list[], int target, int left, int right) {
    int middle;
    while (left <= right) {
        middle = (left + right) / 2;
        switch (COMPARE(list[middle], target)) {
            case -1:
                left = middle + 1;
                break;
            case 0:
                return middle;
                break;
            case 1:
                right = middle - 1;
                break;
        }
    }
    return -1;
}

int main(void) {
    int i, n;
    int list[MAX_SIZE];
    printf("Enter the number of numbers to generate: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        list[i] = rand() % 1000;
        printf("%d ", list[i]);
    }

    sort(list, n);
    printf("\n Sorted Array \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
    int target;
    printf("Please input search num: ");
    scanf("%d", &target);
    printf("%d position in list[%d]\n", target,
           BinarySearch(list, target, 0, n - 1));
}

void sort(int* list, int n) {
    int min, temp;
    for (int i = 0; i < n; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (list[j] < list[min]) {
                min = j;
            }
        }
        SWAP(list[i], list[min], temp);
    }
}