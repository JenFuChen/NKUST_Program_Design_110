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

listPointer head = NULL, tail = NULL;

void addQ(int item) {
    listPointer node;
    node = (listPointer)malloc(sizeof(*node));
    node->data = item;
    node->link = NULL;
    if (head == NULL) {
        head = node;
        tail = node;
    } else {
        tail->link = node;
        tail = node;
    }
}

int deleteQ() {
    if (head != NULL) {
        listPointer temp = head;
        head = head->link;
        if (head == NULL) {
            tail = NULL;
        }
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
    addQ(10);
    addQ(20);
    addQ(30);
    printf("del=%d\n", deleteQ());
    printf("del=%d\n", deleteQ());
    printf("del=%d\n", deleteQ());
    // system("pause");
}
