// 1102

// Author: 四子三丙 陳人輔 C110152319
// Class : 資料結構
// Description : Stack

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 2

int stack[MAX_STACK_SIZE];
int top = -1;

void push(int term) {
    if (top >= MAX_STACK_SIZE - 1)
        printf("\nFULL!\n");
    else
        stack[++top] = term;
}

int pop() {
    return (top == -1 ? -1 : stack[top--]);
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    printf("POP = %d\n", pop());
    printf("POP = %d\n", pop());
    printf("POP = %d\n", pop());
}