// Linking List

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

typedef struct listNode* listPointer;

typedef struct listNode {
    char data[4];
    listPointer link;
} ListNode;

int main() {
    listPointer first = NULL;
    listPointer second = NULL;
    listPointer third = NULL;

    first = (listPointer)malloc(sizeof(*first));
    second = (listPointer)malloc(sizeof(*second));
    third = (listPointer)malloc(sizeof(*third));

    strcpy(first->data, "BAT");
    strcpy(second->data, "CAT");
    strcpy(third->data, "EAT");

    first->link = second;
    second->link = third;
    third->link = NULL;
    for (; first != 0;) {
        printf("%s ", first->data);
        first = first->link;
    }
    printf("\n");

    return 0;
}