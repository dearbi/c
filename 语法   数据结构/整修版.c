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

//删除链表重复元素
int count=0;
node* del_repeat(node*head,int n)
{
    node* cur=head;
    while(cur!=NULL)
    {
        node* pre=cur;
        node* runner=cur->next;

        while(runner!=NULL)
        {
            if(runner->data==cur->data)
            {
                count++;
                pre->next=runner->next;
                free(runner);
                runner=pre->next;
            }
            else{
                pre=runner;
                runner=runner->next;
            }
        }
        cur=cur->next;
    }
    return head;
}


// 在第m个节点后插入x
node* insert_middle(node* head,int m,int x)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=x;
    newnode->next=NULL;
    if(head==NULL||m==0)
    {
        newnode->next=head;
        head=newnode;
        return head;
    }
    node* cur=head;
    int count=1;
    while(cur!=NULL&&count<m)
    {
        cur=cur->next;
        count++;
    }
    if(cur!=NULL)
    {
        newnode->next=cur->next;
        cur->next=newnode;
    }
    else{
        node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
    return head;
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
node* merge_list(node* head1,node* head2)
{
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    node* fri=head1;
    node* sec=head2;
    node* head=NULL;
    node* tail=NULL;

    if(fri->data < sec->data)
    {
        head=fri;
        fri=fri->next;
    }
    else{
        head=sec;
        sec=sec->next;
    }
    tail=head;

    while(fri&&sec)
    {
        if(fri->data<=sec->data)
        {
            tail->next=fri;
            fri=fri->next;
        }
        else{
            tail->next=sec;
            sec=sec->next;
        }
        tail=tail->next;
    }

    if(sec)
    {
        tail->next=sec;
    }
    else if(fri)
    {
        tail->next=fri;
    }

    return head;
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
            if (even_head== NULL) {
                even_head = even_tail = new_node;
                odd_head = odd_tail = NULL;
                head = head->next;
            }
        }
        else {
            if (odd_head == NULL) {
                odd_head = odd_tail = new_node;
                even_head = even_tail = NULL;
                head = head->next;
            }
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
    del_repeat(head,count);
    print_list(head);
    printf("——————————————");
    for(int i=0;i<n;i++)
    {
        int index;int x;
        scanf("%d",&index);
        scanf("%d",&x);
        head=insert_middle(head,index,x);
    }
    print_list(head);
    printf("——————————————");
    delete_repeat_reverse(head);
    print_list(head);
    printf("——————————————");
    split_list(head);

    return 0;
}
