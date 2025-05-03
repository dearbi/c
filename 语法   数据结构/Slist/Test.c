#include "Slist.h"
void SListTest()
{
    //链表是由一个一个节点组成
    //创建几个节点
    SLTNode *node1 =(SLTNode*)malloc(sizeof(SLTNode));
    node1->data = 1;
    SLTNode *node2 =(SLTNode*)malloc(sizeof(SLTNode));
    node2->data = 2;
    SLTNode *node3 =(SLTNode*)malloc(sizeof(SLTNode));
    node3->data = 3;
    SLTNode *node4 =(SLTNode*)malloc(sizeof(SLTNode));
    node4->data = 4;

    //将四个节点链接起来
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;

    //调用链表的打印
    SLTNode* plist=node1;
    SLTPrint(plist);
}
void SListTest2()
{
    SLTNode* plist =NULL;
    SLTPushBack(&plist,1);
    SLTPrint(plist);

}
int main()
{
//  SListTest();
    SListTest2();
    return 0;
}