// 1130

// Author: 四子三丙 陳人輔 C110152319
// Class : 資料結構
// Description : Tree

#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode* treePointer;
typedef struct treeNode {
    int data;
    treePointer left, right;
} ListNode;

void postOrder(treePointer ptr) { /* 後序走訪法 */
    if (ptr) {
        postOrder(ptr->left);
        postOrder(ptr->right);
        printf("%d ", ptr->data);
    }
}

void preOrder(treePointer ptr) { /* 前序走訪法 */
    if (ptr) {
        printf("%d ", ptr->data);
        preOrder(ptr->left);
        preOrder(ptr->right);
    }
}

void inOrder(treePointer ptr) { /* 中序走訪法 */
    if (ptr) {
        inOrder(ptr->left);
        printf("%d ", ptr->data);
        inOrder(ptr->right);
    }
}

int main() {
    treePointer first, second, third;
    first = (treePointer)malloc(sizeof(*first));
    second = (treePointer)malloc(sizeof(*second));
    third = (treePointer)malloc(sizeof(*third));

    first->left = second;
    first->right = third;
    first->data = 10;

    second->left = NULL;
    second->right = NULL;
    second->data = 20;

    third->left = NULL;
    third->right = NULL;
    third->data = 30;

    inOrder(first);
    printf("\n");
    postOrder(first);
    printf("\n");
    preOrder(first);
    printf("\n");

    return 0;
}
