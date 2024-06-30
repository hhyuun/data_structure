// 원형 큐
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5 

typedef int element;
typedef struct{
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void init_queue(QueueType *q)
{
	q->front = q->rear = 0;
}

int is_full(QueueType *q){
    return (q->rear+1) % MAX_QUEUE_SIZE == q->front;
}

void enqueue(QueueType *q, element item){
    // overfolw를 체크 필요. 정적배열이니까 !
    if(is_full(q)){
        printf("큐 포화상태\n");
    }
    q->rear = (q->rear +1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

int is_empty(QueueType *q){
    return q->front == q->rear;
}

element dequeue(QueueType *q){
    // underflow 체크 필요
    if(is_empty(q)){
        printf("큐 공백상태\n");
    }
    q->front = (q->front +1) % MAX_QUEUE_SIZE;
    return q->data[q->front];

}

int main(){
    QueueType queue; // 구조체 변수. 메모리 할당하는 선언문

    int element;

    init_queue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    //element res = dequeue(&queue); // 10이 나와야 함 
    element = dequeue(&queue);
    printf("%d\n", element);
    element = dequeue(&queue);
    printf("%d\n", element);
}