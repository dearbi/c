#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
struct node {
    int ch;
    struct node* next;
};

// 统计链表节点数量
void countnode(struct node* head);

// 创建链表
struct node* setlink(int N);
#include<stdio.h>

#include<stdlib.h>
int main()
{
    int i, N;
    return 0;
}

int main()
{
    int i, N;
    struct node* head;
    scanf("%d", &N);
    head = setlink(N);
    countnode(head);
    return 0;
}

// 创建链表函数
struct node* setlink(int N) {
    struct node* head, * p, * x;
    int i;
    char k;

    if (N > 10)
        k = 'A';
    else
        k = 'a';
    x = (struct node*)malloc(sizeof(struct node));
    x->ch = k;
    x->next = NULL;
    p = x;
    head = x;
    for (i = 1; i < N; i++)
    {
        x = (struct node*)malloc(sizeof(struct node));
        x->ch = k + i;
        x->next = NULL;
        p->next = x;
        p = x;
    }
    return head;
}