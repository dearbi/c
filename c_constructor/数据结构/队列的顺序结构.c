#include <stdio.h>

typedef struct {
	int data[100];
	int front;
	int rear;//"指针"就是所谓的数组下标
}Queue;

void initQueue(Queue* q){
	q->front=0;
	q->rear=0;
}

int isEmpty(Queue* q){
	return q->front==q->rear;	
}

// 添加isFull函数定义
int isFull(Queue* q){
    return q->rear >= 100; // 当rear达到数组大小时队列满
}

//出队
int deQueue(Queue* q){
	if(isEmpty(q)){
		printf("队列为空,无法出队\n");
		return -1;
	}
	int value=q->data[q->front];
	q->front=q->front+1;
	return value;
}

//入队
void enQueue(Queue* q,int value){
	if(isFull(q)){
		//队列已满，需要移动元素
		if(q->front>0){
			//有空间可以移动
			for(int i=0;i<q->rear-q->front;i++){
				q->data[i]=q->data[q->front+i];
			}
			q->rear=q->rear-q->front;
			q->front=0;
		}else{
			//队列真的满了
			printf("队列已满，无法入队\n");
			return;
		}
	}
	//在队列添加元素
	q->data[q->rear]=value;
	q->rear++;
}

int main(){

    Queue q;
    initQueue(&q);
    printf("初始化队列并填充元素\n");
    for (int i = 0; i < 100; ++i) {
        enQueue(&q,i);
    }
    printf("队列已填满，front=%d,rear=%d",q.front,q.rear);

    //出队三个元素，制造前三个位置为空
    for (int i = 0; i < 3; ++i) {
        printf("出队元素：%d\n",deQueue(&q));
    }
    printf("出队三个元素后，front=%d,rear=%d",q.front,q.rear);

    //继续尝试入队，此时会出发元素移动
    enQueue(&q,1001);
    enQueue(&q,1002);
    enQueue(&q,1003);
    printf("入队三个元素后，front=%d,rear=%d\n",q.front,q.rear);

    printf("对头元素:%d\n",q.data[q.front]);
    printf("队尾元素:%d\n",q.data[q.rear-1]);
	
	
	return 0;
}
