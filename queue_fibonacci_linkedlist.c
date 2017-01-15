//
//  main.c
//  queue_fibonacci
//
//  Created by Minjeong's Mac on 2016. 10. 20..
//  Copyright (c) 2016년 Minjeong's Mac. All rights reserved.
//

#include "stdio.h"
#include "stdlib.h"

typedef int element;
typedef struct Queuenode{

    element item;
    struct Queuenode *link;
}Queuenode;

typedef struct{

    Queuenode *front, *rear;
}Queuetype;

void error(char *message)
{

    fprintf(stderr,"s\n",message);
    exit(1);
}

void display(Queuetype *q)
{

    Queuenode *q1 = (Queuenode *)malloc(sizeof(Queuenode));
    
    q1 = q->front;
    while(q1 != NULL)
    {
    printf("%d->",q1->item);
    q1 = q1->link;
    }
}


void init(Queuetype *q)
{

    q->front = q->rear = NULL;
}

int is_empty(Queuetype *q)
{
    return (q->front==NULL);
}

void enqueue(Queuetype *q,element item)
{
    Queuenode *temp = (Queuenode *)malloc(sizeof(Queuenode));
    if(temp==NULL)
        error("memory allocation error");
    else{
    
    temp->link = NULL;
    temp->item = item;
        if(is_empty(q))
        {
            q->front = temp;
            q->rear = temp;
        }
        else
        {
            q->rear->link = temp;
            q->rear = temp;
        }
    }
}

element dequeue(Queuetype *q)
{
    

    Queuenode *temp = q->front;
    if(is_empty(q))
        error("no item to dequeue");
    

    element data;
    data = temp->item;
    q->front = q->front->link;
    if(q->front==NULL)
        q->rear = NULL;
    free(temp);
    return data;
}

element peek(Queuetype *q)
{
    if(is_empty(q))
        error("empty queue");
    element data;
    data = q->front->item;
    return data;
    
}

void fibonacci(Queuetype *q,int num)
{
    element item;

    int i;
    enqueue(q,0);
    enqueue(q,1);
    printf("%d\n",q->front->item);
    if(num==2)
        printf("%d",q->rear->item);
    else if(num>2){
        printf("%d\n",q->rear->item);
        for(i=0;i<num-2;i++)
        {
            item = q->front->item + q->rear->item;
            enqueue(q,item);
            printf("%d\n",q->rear->item);
            dequeue(q);
        }
    }
}


void main(){

    Queuetype q;
    init(&q);
    fibonacci(&q,2);
  
    

}
