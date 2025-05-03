#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* head_insert(node* head, int n) {
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        node* new_node = (node*)malloc(sizeof(node));
        new_node->data = x;
        new_node->next = head;
        head = new_node;
    }
    return head;
}

node* tail_insert(node* head, int n) {
    node* tail = NULL;
    if (head != NULL) {
        tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
    }

    for (int i = 0; i < n; i++) {
        node* new_node = (node*)malloc(sizeof(node));
        int x;
        scanf("%d", &x);
        new_node->data = x;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }
    return head;
}

void print_list(node* head)
{
    node* temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

node* reverse_list(node* head) {
    node* pre = NULL;
    node* curr = head;
    node* next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
    }
    return pre;
}

int main() {
    int n;
    scanf("%d", &n);
    node* head = NULL;
    head = head_insert(head, n);
    print_list(head);
    head = reverse_list(head);
    print_list(head);
     head = tail_insert(head, n);
     print_list(head);

    return 0;
}
