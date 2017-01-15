//
//  main.c
//  queue_by_minjeong
//
//  Created by Minjeong's Mac on 2016. 10. 20..
//  Copyright (c) 2016년 Minjeong's Mac. All rights reserved.
//



#include <stdio.h>

#define MAX_QUEUE_SIZE 100
typedef int element;
typedef struct{

    element queue[MAX_QUEUE_SIZE];
    int front, rear;
    int lastOp; //  데이터 삽입시 1 데이터 삭제시 0
}Queuetype;

void error(char *message)
{

    fprintf(stderr,"%s\n",message);
    exit(1);
}

void init(Queuetype *q)
{
    q->lastOp=0; //
    q->front = q->rear = 0;
}

int is_empty(Queuetype *q)
{
    return ((q->lastOp==0)&&(q->front == q->rear)); // 직전 액션이 삭제이고(lastOp=0) front=rear
}

int is_full(Queuetype *q)
{

    return ((q->lastOp==1)&&(q->front == q->rear)); // 직전 액션이 삽입이고(lastOp=1) front=rear

}

void enqueue(Queuetype *q, element item)
{

    if(is_full(q))
        error("큐가 포화 상태");
    else if(is_empty){
        q->queue[q->rear]=item;
        q->lastOp=1;
        q->rear++;

        }
        else{
        q->queue[q->rear] = item;
        q->rear = (q->rear+1) % MAX_QUEUE_SIZE;
            q->lastOp=1;
        }
}

element dequeue(Queuetype *q)
{
    element item;
    if(is_full(q))
        error("empty");
    item= q->queue[q->front];
    q->front=(q->front+1)%MAX_QUEUE_SIZE;
    q->lastOp = 0;
    return item;
}



element peek(Queuetype *q)
{

    if(is_empty(q))
        error("empty queue");
    return q->queue[q->front];
}


void main(){

    Queuetype q;
    init(&q);
    printf("front value = %d, rear value = %d\n",q.front,q.rear);
    enqueue(&q,1);
    enqueue(&q,2);
    enqueue(&q,3);
    printf("dequeue() = %d \n",dequeue(&q));
    printf("dequeue() = %d \n",dequeue(&q));
    printf("dequeue() = %d \n",dequeue(&q));
    printf("front value = %d, rear value = %d",q.front,q.rear);
 
  }