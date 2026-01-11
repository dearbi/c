#include <stdio.h>
#include <stdbool.h>
typedef struct Stack{
	int data[100];
	int top;
}Stack;


//入栈
void initStack(Stack* stack){
	stack->top=-1;//top并非指针，本质上就是一个int类型的数字，用于记录当前栈顶的位置
}

bool isEmpty(Stack* stack){
	return stack->top==-1;
}

//出栈
int  pop(Stack* stack){
	if(!isEmpty(stack)){
		int value = stack->data[stack->top];
		stack->top--;
		return value;
	}else{
		printf("栈空，无法出栈\n");
		return -1;
	}
}

//入栈
void push(Stack* stack,int value){
	if(stack->top<99)
	{
		stack->top++;
		stack->data[stack->top]=value;
	}
	else{
		printf("栈满，无法入栈\n");
	}
}

int main(){
	Stack stack;
	initStack(&stack);
	push(&stack,1);
	push(&stack,2);
	push(&stack,3);
	
	while(!isEmpty(&stack)){
		int poppedValue=pop(&stack);
		if(poppedValue!=-1){
			printf("出栈元素：%d\n",poppedValue);
		}
	}
	//这个地方的判断方法有很多~

	return 0;
}
