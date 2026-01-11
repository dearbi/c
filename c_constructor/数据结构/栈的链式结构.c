#include <stdio.h>

typedef struct Stack{
	int data;
	struct Stack* next;
}Stack;

//入栈
void push(Stack *head,int value){
	Stack *newNode=(Stack*)malloc(sizeof(Stack));
	newNode->data=value;
	
	newNode->next=head->next;
	head->next=newNode;
	
}

//出栈
int pop(Stack *head,int *value){
	if(head->next==NULL){
		printf("空的\n");
		return 0;
	}
	*value=head->next->data;
	Stack *tempNode=head->next;
	head->next=tempNode->next;
	free(tempNode);
	return 1;
}
int main(){
	Stack* head=(Stack*)malloc(sizeof(Stack));
	head->next=NULL;
	push(head,1);
	push(head,2);
	push(head,3);
	int value;
	while(pop(head,&value)){
		printf("%d\n",value);
	}
	return 0;
}
