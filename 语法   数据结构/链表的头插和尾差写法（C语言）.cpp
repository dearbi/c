#include <stdio.h>
#include <stdlib.h>
//头插法
typedef struct Node {
    int data;
    struct Node* next;
} Node;


void head_insert(Node** head, int val) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = val;
    new_node-> next = *head;
    *head = new_node;
}

//尾插法
typedef struct {
    Node* head;
    Node* tail;  // 专门记录尾节点
} LinkedList;

void tail_insert_opt(LinkedList* list, int val) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = val;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}