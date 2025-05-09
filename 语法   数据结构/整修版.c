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

//翻转链表
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


//头删
node* delete_head(node* head) {
    if (head == NULL) {
        return NULL;
    }
    node* temp = head;
    head = head->next;
    free(temp);
    return head;
}
//尾删
node* delete_tail(node* head) {
    if (head == NULL) {
        return NULL;
    }
    node* temp = head;
    node* pre = NULL;
    while (temp->next != NULL) {
        pre = temp;
        temp = temp->next;
    }
    pre->next = NULL;
    free(temp);
    return head;
}
//单链表中重复元素的删除
node* delete_repeat(node* head) {
    node* pre = NULL;
    node* curr = head;
    while (curr != NULL) {
        if (curr->next != NULL && curr->data == curr->next->data) {
            node* temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        } else {
            pre = curr;
            curr = curr->next;
        }
    }
}

//在链表的中间插入一个节点:每次操作为在链表的第 m 个元素后面插入一个新元素x,若m 大于链表的元素总数则将x放在链表的最后。
node* insert_middle(node* head, int x) {
    node* temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    int m = (count + 1) / 2;
    temp = head;
    for (int i = 1; i < m; i++) {
        temp = temp->next;
    }
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = x;
}

//按照数据输入的相反顺序（逆位序）建立一个单链表，并将单链表中重复的元素删除（值相同的元素只保留最后输入的一个）
node* delete_repeat_reverse(node* head) {
    node* pre = NULL;
    node* curr = head;
    while (curr != NULL) {
        if (curr->next != NULL && curr->data == curr->next->data) {
            node* temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        } else {
            pre = curr;
            curr = curr->next;
        }
    }
    return reverse_list(head);
}

//分别输入两个有序的整数序列（分别包含M和N个数据），
// 建立两个有序的单链表，将这两个有序单链表合并成为一个大的有序单链表，
// 并依次输出合并后的单链表数据
node* merge_list(node* head1, node* head2) {
    node* head = NULL;
    node* tail = NULL;
    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            node* new_node = (node*)malloc(sizeof(node));
            new_node->data = head1->data;
            new_node->next = NULL;
            if (head == NULL) {
                head = new_node;
               tail = new_node;
            }
        }
    }
}
//输入N个整数顺序建立一个单链表，将该单链表拆分成两个子链表，
// 第一个子链表存放了所有的偶数，第二个子链表存放了所有的奇数。
// 两个子链表中数据的相对次序与原链表一致
node* split_list(node* head) {
    node* even_head = NULL;
    node* even_tail = NULL;
    node* odd_head = NULL;
    node* odd_tail = NULL;

    while (head != NULL) {
        node* new_node = (node*)malloc(sizeof(node));
        new_node->data = head->data;
        new_node->next = NULL;

        if (new_node->data % 2 == 0) {
            if (even_head== NULL) {}
        }
    }
    return even_head, odd_head;
}

int main() {
    int n;
    scanf("%d", &n);
    node* head = NULL;
    head = head_insert(head, n);
    print_list(head);
    printf("——————————————");
    head = reverse_list(head);
    print_list(head);
    printf("——————————————");
    head = tail_insert(head, n);
    print_list(head);
    printf("——————————————");
    head = delete_head(head);
    print_list(head);
    printf("——————————————");
    head = delete_tail(head);
    print_list(head);
    printf("——————————————");
    delete_repeat(head);
    print_list(head);
    printf("——————————————");
    insert_middle(head, 5);
    print_list(head);
    printf("——————————————");
    delete_repeat_reverse(head);
    print_list(head);

    return 0;
}
