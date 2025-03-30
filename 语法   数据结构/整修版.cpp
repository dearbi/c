#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void head_insert(node** head, int n) {
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        node* new_node = (node*)malloc(sizeof(node));
        new_node->data = x;
        new_node->next = *head;
        *head = new_node;
    }
}

void tail_insert(node** head, int n) {
    node* tail = NULL;
    for (int i = 0; i < n; i++) {
        node* new_node = (node*)malloc(sizeof(node));
        int x;
        scanf("%d", &x);
        new_node->data = x;
        new_node->next = NULL;

        if (*head == NULL)
        {
            *head = new_node;
            tail = new_node;
        } else
        {
            tail->next = new_node;
            tail = new_node;
        }
    }
}

void print_list(node* head) {
    node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

node* reverse_list(node* head)
{
    node* pre=NULL;
    node* curr= head;
    node* next=NULL;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=pre;
        pre=curr;
        curr=next;
    }
    return pre;
}

int main() {
    int n;
    scanf("%d", &n);
    node* head = NULL;
    head_insert(&head, n);
    print_list(head);
    head=reverse_list(head);
    print_list(head);
//    tail_insert(&head, n);
//    print_list(head);

    return 0;
}