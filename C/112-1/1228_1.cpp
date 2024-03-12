#include <stdio.h>
#include <stdlib.h>
#define M 11
#define NUM 9
#define YES 1
#define NO 0

struct node {
    int data;
    struct node* next;
};

typedef struct node NODE;
void insert(NODE**, NODE*);
void showhash(NODE**);
void printlist(NODE*);
int* search(NODE*, int);
int main() {
    int i = 0, key;
    NODE* hash[M] = {
        NULL,
    };
    NODE* newnode;

    //  clrscr();
    // int x=srand(time(NULL))%100;
    int ky[9] = {22, 4, 12, 69, 340, 15, 10, 59, 55};
    while (i < NUM) {
        newnode = (NODE*)malloc(sizeof(*newnode));  // 配置節點
        newnode->data = ky[i];  // 產生一個1~100的亂數
        newnode->next = NULL;
        insert(
            &(hash[newnode->data % M]),
            newnode);  // 將newnode 插入到hashtable 的 newnode->data % M的串列裡
        i++;
    }

    showhash(hash);

    printf("Please enter a number\n");
    scanf("%d", &key);

    if (search(hash[key % M], key) != NULL)
        printf("FOUND\n");
    else
        printf("NOT FOUND\n");

    printf("\n");
    return 0;
}

void insert(NODE** head, NODE* newnode) {
    // if *head 是NULL
    if (*head == NULL)
        *head = newnode;
    //    *head 設為 newnode
    else
        insert(&((*head)->next), newnode);
    // else
    //
    //    用(*head)->next的位址呼叫insert()
}

void showhash(NODE** hash) {
    int i;

    for (i = 0; i < M; i++)
        printlist(hash[i]);
}

void printlist(NODE* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        // print head的data
        head = head->next;
        // head 移動下個節點位址
    }
    printf("NULL\n");
}

int* search(NODE* head, int key) {
    if (head == NULL)
        return NULL;
    else if (head->data == key)
        return &(head->data);
    else
        return search(head->next, key);
}