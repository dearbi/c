#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int data[100];
	int length;
}SeqList;

//初始化长度
void initSeqlist(SeqList* list){
	list->length=0;
}

//在顺序表的尾部插入元素
int addpendElement(SeqList* list,int element){
	//检查表是否已满
	if(list->length >= 100){
		return 0;
	}
	//在尾部插入元素
	list->data[list->length]=element;
	list->length++;
	return 1;
}

//在指定位置添加新的元素
int insertElement(SeqList* list,int position,int element){
	//检查表是否已满
	if(list->length>=100){
		return 0;
	}
	
	//检查位置是否合法
	if(position<0||position>list->length){
		return 0;
	}
	
	//将position及以后的元素依次往后移动一位
	for(int i=list->length;i>position;i--){
		list->data[i]=list->data[i-1];
	}
	
	//在position处插入元素
	list->data[position]=element;
	list->length++;
	return 1;
}

//删除指定位置的元素
int deleteElement(SeqList* list,int position){
	//检查位置是否合法
	if(position<0||position>list->length){
		return 0;
	}
	//将position之后的元素前移一位
	for(int i=position;i<list->length-1;i++){
		list->data[i]=list->data[i+1]; 
	}
	//减少顺序表的长度
	list->length--;
	return 1;
}

//删除所有值为val的元素
void removeAllVal(SeqList* list, int val){
	//空直接返回
	if(list->length==0){
		return ;
	}
	//双指针
	int left=0;
	for(int right=0;right<list->length;right++){
		//如果当前元素不等于val，保留
		if(list->data[right]!=val){
			list->data[left]=list->data[right];
			left++;
		}
		//等于val，跳过
	}
	int count=list->length-left;
	list->length=left;
}

//查找指定元素
int findIndex(SeqList* list,int element){
	for(int i=0;i<list->length;i++){
		if(list->data[i]== element){
			return i;
		}
	}
	return -1;
}

//清空顺序表
void deleteAll(SeqList* list){
	list->length=0; //将长度设置为0
}

int main(){
	SeqList list;
	initSeqlist(&list);
	printf("初始化后，长度为：%d\n",list.length);
	size_t memorySize=sizeof(list.data);
	printf("内存占用为：%d\n",memorySize);
	addpendElement(&list,1);
	addpendElement(&list,2);
	addpendElement(&list,3);
	addpendElement(&list,2);
//	insertElement(&list,0,999);
//	deleteElement(&list,0);
	printf("顺序表中的元素：");
	for(int i=0;i<list.length;i++){
		printf("%d ",list.data[i]);
	}
	printf("\n");
//	int x;
//	printf("请输入需要查找的元素 :");
//	scanf("%d",&x);
//	int index=findIndex(&list,x);
//	printf("角标 为%d 的元素是%d",index,list.data[index]);
	removeAllVal(&list,2);
	for(int i=0;i<list.length;i++){
		printf("%d ",list.data[i]);
	}
	return 0;
}


