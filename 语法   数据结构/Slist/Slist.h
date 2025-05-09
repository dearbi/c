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
    assert(pphead);
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


void SLTPushFront(SLTNode** pphead,SlistDataType x)
{
    assert(pphead);
    SLTNode *newnnode=  SLTBuyNode(x);
    newnnode->next=*pphead;
    *pphead=newnnode;
}

//尾删
void SLTPopBack(SLTNode** pphead)
{
    assert(pphead);
    if(*pphead==NULL)
    {
        return;
    }
    else if((*pphead)->next==NULL)
    {
        free(*pphead);
        *pphead=NULL;
    }
    else
    {
        SLTNode* ptail=*pphead;
        while(ptail->next->next!=NULL)
        {
            ptail=ptail->next;
        }
        free(ptail->next);
        ptail->next=NULL;
    }
}
