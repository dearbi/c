#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	int data;
	struct Node* next;
}Node;


//初始化链表
Node* initLinkList(){
	Node* newNode=(Node*)malloc(sizeof(Node));
	if(newNode==NULL){
		printf("内存分配失败\n");
		return NULL;
	}
	newNode->data=0;
	newNode->next=NULL;
	return newNode;
}


//头插法
void insertATHead(Node* head,int value){
	Node* newNode=(Node*)malloc(sizeof(Node));
	if(newNode==NULL){
		printf("内存分配失败\n");
		return ;
	}
	newNode->data=value;
	newNode->next=head->next;
	head->next=newNode;
	printf("成功插入节点，数据为：%d\n",value);
}

//尾插法
void insertAtTail(Node* head,int value){
	Node* newNode=(Node*)malloc(sizeof(Node));
	if(newNode==NULL){
		printf("内存分配失败\n");
		return ;
	}
	newNode->data=value;
	newNode->next=NULL;//新节点将成为尾节点，所有next为NULL
	
	//找到当前尾节点
	Node* current=head;
	while(current->next!=NULL){
		current=current->next;
	}
	
	//将新节点连接到尾部
	current->next=newNode;
	printf("成功插入尾节点，数据为：%d\n",value);
}


//指定位置插入元素
void insertAtPosition(Node* head,int value,int position){
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=value;
	
	//找到要插入位置的前一个节点
	Node* current =head;
	int count =0;
	while(count<position-1){
		current=current->next;
		count++;
	}
	
	//插入新节点
	newNode->next=current->next;
	current->next=newNode;
	printf("成功在位置%d插入节点，数据为：%d\n",position,value);
}


//遍历链表
void traverseList(Node* head){
	if(head==NULL){
		printf("链表为空\n");
		return;
	}
	printf("链表中的所有节点数据：\n");
	Node* current=head->next;
	while(current!=NULL)
	{
		printf("%d ",current->data);
		current=current->next;
	}	
	printf("\n");
}



int main(){
	Node* head=initLinkList();
	if(head!=NULL){
		printf("头结点创建成功! 数据为：%d\n",head->data);
	}
	//使用头插法插入数据
	insertATHead(head,1);
	insertATHead(head,2);
	
	traverseList(head);
	
	insertATHead(head,3);
	insertATHead(head,4);
	
	traverseList(head);
	
	//使用尾插法插入元素
	insertATHead(head,7);
	insertAtTail(head,8);
	
	traverseList(head);
	
	insertAtPosition(head,9,3);
	
	traverseList(head);
	
	


	return 0;
}
