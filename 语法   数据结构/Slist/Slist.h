#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SlistDataType;


typedef struct SlistNode{
    SlistDataType data;
    struct SlistNode *next;
}SLTNode;



void SLTPrint(SLTNode* phead)
{
    SLTNode* pcur=phead;
    while(pcur!=NULL)
    {
        printf("%d->",pcur->data);
        pcur=pcur->next;
    }
    printf("NULL");
}


SLTNode *SLTBuyNode(SlistDataType x)
{
    SLTNode *newnode=(SLTNode*) malloc(sizeof(SLTNode));
    if(newnode==NULL)
    {
        perror("malloc fail");
        exit(1);
    }
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}

void SLTPushBack(SLTNode** pphead,SlistDataType x)
{
    SLTNode* newnode= SLTBuyNode(x);

    if(*pphead==NULL)
    {
        *pphead=newnode;
    }
    else {
        //找尾
        SLTNode* ptail = *pphead;
        while (ptail->next != NULL) {
            ptail = ptail->next;
        }
        ptail->next = newnode;
    }
}


void SLTPushFront(SLTNode** phead,SlistDataType x)
{

}
