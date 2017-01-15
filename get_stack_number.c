//
//  main.c
//  get_stack_number
//
//  Created by Minjeong's Mac on 2017. 1. 12..
//  Copyright (c) 2017년 Minjeong's Mac. All rights reserved.
//

#include <stdio.h>
typedef int element;
typedef struct stackNode{
    element data;
    struct stackNode* link;
}stackNode;

typedef struct stackType{

    stackNode* top;
}stackType;

void push(stackType*s , element data){
    stackNode *node;
    node=(stackNode*)malloc(sizeof(stackNode));
    if(node==NULL)
        return;
    node->data = data;
    node->link = s->top;
    s->top = node;
}

void init(stackType *s)
{
    s->top = NULL;
}


int node_count(stackType *s)
{
    int count=0;
    while(s->top!=NULL)
    {count++;
       s->top = (s->top)->link;
    }
    return count;

}

void main(){


    stackType s;
    init(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    int a = node_count(&s);
    printf("%d",a);
    
}