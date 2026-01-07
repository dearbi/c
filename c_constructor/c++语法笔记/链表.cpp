#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int x=9;
	int val;
	Node(int _val): val(_val),next(NULL) {}
	Node* next;
};
int main()
{
	Node* p =new Node(1);
	Node* q =new Node(2);
	Node* o =new Node(3);
	
	p->next=q;
	q->next=o;
	
	Node* head =p;
	
	//添加节点
	Node* u=new Node(4);
	u->next=head;
	head=u;
	
	//删除节点
//	head->next=head->next->next;
	
	
	//链表的遍历方式
	for(Node* i=head;i;i=i->next)
	cout<<i->val<<endl;
		
	return 0;
}