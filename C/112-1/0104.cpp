#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 20

void mergesort(int*, int*, int, int);
void merge(int*, int*, int, int, int);

int main() {
    int data[NUM];
    int workspace[NUM];
    int i;
    printf("\n===== ORIGIN LIST =====\n");
    for (i = 0; i < NUM; i++) {
        data[i] = rand() % 100 + 1;
        printf("%3d", data[i]);
    }
    printf("\n-----------------------------------------------------------\n");
    printf("\nSorting....\n");
    
    mergesort(data, workspace, 0, NUM - 1);
     printf("\n-----------------------------------------------------------\n");
    printf("\n===== SORTED LIST =====\n");
    for (i = 0; i < NUM; i++)
        printf("%3d", data[i]);
    printf("\n");
    return 0;
}

void mergesort(int* data, int* workspace, int front, int rear) {
    int mid, i;

    if (front < rear) {
        mid = (front + rear) / 2;
        mergesort(data, workspace, front, mid);
        mergesort(data, workspace, mid + 1, rear);
        merge(data, workspace, front, mid, rear);
        for (i = front; i <= rear; i++)
            data[i] = workspace[i];
    }
}

void merge(int* data, int* workspace, int front, int mid, int rear) {
    int input = front;
    int input1 = mid + 1;
    int output = front;

    while (input <= mid && input1 <= rear) {
        if (data[input] < data[input1] || data[input] == data[input1])
            workspace[output++] = data[input++];
        else
            workspace[output++] = data[input1++];
    }
    while (input <= mid)
        workspace[output++] = data[input++];
    
    while (input1 <= rear)
        workspace[output++] = data[input1++];
}