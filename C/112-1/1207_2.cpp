// 1207

// Author: 四子三丙 陳人輔 C110152319
// Class : 資料結構
// Description :運算式二元樹建立

#include <stdio.h>
#include <stdlib.h>

typedef struct node* treePointer;
typedef struct node {
    char data;  // 運算元
    treePointer left, right;
} Node;

typedef struct listNode* listPointer;
typedef struct listNode {
    treePointer data;
    listPointer link;
} ListNode;

listPointer top = NULL;

void push(treePointer item) {
    listPointer node;
    node = (listPointer)malloc(sizeof(*node));
    node->data = item;
    node->link = NULL;
    if (top == NULL)  // if top is null
    {
        top = node;
    } else {
        node->link = top;
        top = node;
    }
}

treePointer pop() {
    if (top != NULL)  // if top 不為 NULL
    {
        listPointer temp = top;
        top = top->link;
        treePointer item = temp->data;
        free(temp);
        return (item);
    }
    return NULL;
    // 回傳 NULL
}
void inOrder(treePointer ptr) { /* 中序走訪法 */
    if (ptr) {
        inOrder(ptr->left);
        printf("%c\t", ptr->data);
        inOrder(ptr->right);
    }
}

void postOrder(treePointer ptr) { /* 後序走訪法 */
    if (ptr) {
        postOrder(ptr->left);
        postOrder(ptr->right);
        printf("%c\t", ptr->data);
    }
}

void preOrder(treePointer ptr) { /* 前序走訪法 */
    if (ptr) {
        printf("%c\t", ptr->data);
        preOrder(ptr->left);
        preOrder(ptr->right);
    }
}

int main() {
    char expr[100];
    int i = 0;
    treePointer node;
    treePointer left, right;
    scanf("%s", expr);
    // input 後置式 到  expr   12+7*

    while (expr[i] != '\0')  // if expr[i] is not '\0' continue the loop
    {
        // malloc() treeNode 並將位置 store 在 node
        node = (treePointer)malloc(sizeof(*node));
        node->data = expr[i];
        node->left = NULL;
        node->right = NULL;

        if (expr[i] > 0x30 && expr[i] < 0x3A)  // expr[i] is '1'~'9'
        {
            push(node);
        } else {
            right = pop();
            left = pop();
            node->right = right;
            node->left = left;
            push(node);
        }
        i++;
    }
    treePointer root = pop();
    // store pop() to treePointer root
    printf("> 後置式\n");
    postOrder(root);  // 12+7*
    printf("\n-------------------------------------------------------------");
    printf("\n> 中置式\n");
    inOrder(root);  // 1+2*7
    printf("\n-------------------------------------------------------------");
    printf("\n> 前置式\n");
    preOrder(root);  //*+127
    printf("\n");
    return 0;
}