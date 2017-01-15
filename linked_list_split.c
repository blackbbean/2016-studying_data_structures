//
//  main.c
//  linked_list_split
//
//  Created by Minjeong's Mac on 2016. 11. 25..
//  Copyright (c) 2016년 Minjeong's Mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct listNode{
    
    element data;
    struct listNode* link;
}listNode;

void error(char *message)
{
    
    fprintf(stderr,"%s\n",message);
    exit(1);
}

listNode * create_node(element data, listNode *link)
{
    
    
    listNode *new_node;
    new_node = (listNode*)malloc(sizeof(listNode));
    new_node-> data = data;
    new_node->link = link;
    return new_node;
}

void insert_node(listNode ** phead,listNode *p, listNode *new_node)
{

    if(*phead==NULL)
    {
        new_node -> link = NULL;
        *phead = new_node;
    }
    else if(p==NULL)
    {
    
        new_node->link = *phead;
        *phead = new_node;
    }
    else{
    

        new_node->link = p->link;
        p->link = new_node;
    }
}

void display(listNode *head)
{

    listNode *p = head;
    while(p!=NULL)
    {printf("%d->",p->data);
        p=p->link;}
    printf("\n");
}

 void split(listNode* l3,listNode **l1, listNode **l2)
{

    listNode * p = l3;

    
    while(p!=NULL){
    if((p->data)%2==0)
    {
        insert_node(l1, NULL, create_node(p->data, NULL));
        p=p->link;
    }
    else if((p->data)%2!=0){
    insert_node(l2, NULL, create_node(p->data, NULL));
        p=p->link;
    }
        
    }
    
}


void main(){
     listNode *l1 =NULL;
     listNode *l2 =NULL;
     listNode *l3 =NULL;
    
    insert_node(&l1, NULL, create_node(6,NULL));
     insert_node(&l1, NULL, create_node(5,NULL));
     insert_node(&l1, NULL, create_node(4,NULL));
     insert_node(&l1, NULL, create_node(3,NULL));
     insert_node(&l1, NULL, create_node(2,NULL));
     insert_node(&l1, NULL, create_node(1,NULL));
    
    split(l1, &l2,&l3);
    printf("L2\n");
    display(l2);
    printf("L3\n");
    display(l3);
    
}