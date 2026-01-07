#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int data[101];
	int length;
}Seqlist;

void setLength(Seqlist* list){
	list->length=0;
}
void addElement(Seqlist* list,int x){
	list->data[list->length]=x;
	list->length++;
}

int findIndex(Seqlist* list,int x){
	for(int i=0;i<list->length;i++){
		if(list->data[i]==x){
			return i+1;
		}
	}
	return 0;
}
int main(){
	Seqlist list;
	int n;
	scanf("%d",&n);
	setLength(&list);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		addElement(&list,x);
	}
	
	int m;
	while(scanf("%d",&m)!=EOF){
		if(m!=-1){
			printf("%d ",findIndex(&list,m));
		}
		else break;
	}
	
	return 0;
}
