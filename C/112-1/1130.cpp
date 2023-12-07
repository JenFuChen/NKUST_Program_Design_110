// 1130

// Author: 四子三丙 陳人輔 C110152319
// Class : 資料結構
// Description :Queue

#include <stdio.h>
#include <stdlib.h>

typedef struct listNode* listPointer;
typedef struct listNode {
    int data;
    listPointer link;
} ListNode;

listPointer top = NULL;

void push(int item) {
    listPointer node;
    node = (listPointer)malloc(sizeof(*node));
    node->data = item;
    node->link = NULL;

    if (top == NULL) {
        top = node;
    } else {
        node->link = top;
        top = node;
    }
}

int pop() {
    if (top != NULL) {
        listPointer temp = top;
        top = top->link;
        int item = temp->data;
        free(temp);
        return item;
    }
    return -1;
}

void printList(listPointer first) {
    while (first != NULL) {
        printf("(%p,%d,%p)", first, first->data, first->link);
        first = first->link;
    };
    printf("\n");
}

int main() {
    printf("\n------------------\n");
    push(10);
    printList(top);
    push(20);
    printList(top);
    push(30);
    printList(top);
    printf("POP = %d \n", pop());
    printList(top);
    printf("POP = %d \n", pop());
    printList(top);
    printf("POP = %d \n", pop());
    printf("\n");
    return 0;
}
