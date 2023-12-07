// 1207

// Author: 四子三丙 陳人輔 C110152319
// Class : 資料結構
// Description :二元樹搜尋、建立

#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode* treePointer;

typedef struct treeNode {
    int data;
    treePointer left, right;
} TreeNode;

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

// 遞迴版
int* search(treePointer root, int key) {
    if (root == NULL)
        return NULL;
    else if (key == root->data)
        return &(root->data);
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// 迴圈版
int* iterSearch(treePointer root, int k) {
    while (root) {
        if (k == root->data)
            return &(root->data);
        else if (k < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

void insertBStree(treePointer* root, treePointer node) {
    if (root == NULL)
        treeNode root;
    // if *root == NULL
    //    將 *root 設為 node
    // else if  node 的 data 大於 *root 的 data
    //              再度用 *root 的 right 和 node
    //              呼叫insertBStree(),
    //      else
    //              再度用 *root 的 left 和 node
    //              呼叫insertBStree(),
    //
}

int main() {
    treePointer A, B, C, D, E;
    // 配置一個node空間並讓 A 指向此node 空間的起始位址
    A = (treePointer)malloc(sizeof(*A));
    // 將 A 的 data 設成 35, left 和 right 設成 NULL
    A->data = 35;
    A->left = NULL;
    A->right = NULL;
    // 配置一個node空間並讓 B 指向此node 空間的起始位址
    B = (treePointer)malloc(sizeof(*B));
    // 將 B 的 data 設成 46, left 和 right 設成 NULL
    B->data = 46;
    B->left = NULL;
    B->right = NULL;
    // 配置一個node空間並讓 C 指向此node 空間的起始位址
    C = (treePointer)malloc(sizeof(*C));
    // 將 C 的 data 設成 20, left 和 right 設成 NULL
    C->data = 20;
    C->left = NULL;
    C->right = NULL;
    // 配置一個node空間並讓 D 指向此node 空間的起始位址
    D = (treePointer)malloc(sizeof(*D));
    // 將 D 的 data 設成 27, left 和 right 設成 NULL
    D->data = 27;
    D->left = NULL;
    D->right = NULL;
    // 配置一個node空間並讓 E 指向此node 空間的起始位址
    E = (treePointer)malloc(sizeof(*E));

    // 將 E 的 data 設成 38, left 和 right 設成 NULL
    E->data = 38;
    E->left = NULL;
    E->right = NULL;
    // 將 A的 left 指向 C, right 指向 B
    A->left = C;
    A->right = B;
    // 將 C 的 right 指向 D
    C->right = D;
    // 將 B的 left 指向 E
    B->left = E;
    // 宣告一個 TreePointer root 並指向 A
    treePointer root = A;
    // 二分搜尋樹
    printf("\nNAME\tDATA\tPOSITION\tLEFT\t\tRIGHT\n");
    printf("-------------------------------------------------------------\n");
    printf("A\t%d\t%p\t%p\t%p\n", A->data, A, A->left, A->right);
    printf("B\t%d\t%p\t%p\t%p\n", B->data, B, B->left, B->right);
    printf("C\t%d\t%p\t%p\t\t%p\n", C->data, C, C->left, C->right);
    printf("D\t%d\t%p\t%p\t\t%p\n", D->data, D, D->left, D->right);
    printf("E\t%d\t%p\t%p\t\t%p\n", E->data, E, E->left, E->right);
    printf("-------------------------------------------------------------\n");
    printf("\nSEARCH\n");

    // 呼叫 search() 搜尋 root裡面有無 27 , printf 回傳指標 p 以及*p
    int* target = search(root, 27);
    printf("< %d, %p >\n", *target, target);
    // 呼叫  iterSearch() 搜尋 tree裡面有無 38, printf 回傳指標 p 以及*p
    target = iterSearch(root, 38);
    printf("< %d, %p >\n", *target, target);
    // 呼叫  iterSearch() 搜尋 tree裡面有無 100, printf 回傳指標 p 以及*p
    target = iterSearch(root, 100);
    printf("< %d, %p >\n", *target, target);

    // 建立二分搜尋樹
    // 宣告一個 TreePointer btree, 並設為 NULL
    treePointer BTree = NULL;
    // 呼叫 insertBStree(), 將 E 放入 二分搜尋樹btree
    // 呼叫 insertBStree(), 將 D 放入 二分搜尋樹 btree
    // 呼叫 insertBStree(), 將 C 放入 二分搜尋樹 btree
    // 呼叫 insertBStree(), 將 A 放入 二分搜尋樹 btree
    // 呼叫 insertBStree(), 將 B 放入 二分搜尋樹 btree
    // 呼叫 inorder(), 將 btree的所有節點走一遍
    return 0;
}
