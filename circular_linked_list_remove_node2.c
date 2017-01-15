//
//  main.c
//  circular_linked_list_remove_node2
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

void display(listNode *head)
{
    listNode *p;
    if(head==NULL)
        return;
    
    p = head;
    do{
        printf("%d->",p->data);
        p=p->link;
    }while(p!=head);
    
    printf("end\n");
}


void insert_first(listNode ** phead, listNode *node)
{

    if(*phead==NULL)
    {
        *phead = node;
        node->link = *phead;
    }
    else{
        node->link = (*phead)->link;
        (*phead)->link = node;
    
    }
}


void insert_last(listNode **phead, listNode*node)
{
    if(*phead==NULL)
    {
        *phead = node;
        node->link = *phead;
    }
    else
    {
        node->link = (*phead)->link;
        (*phead)->link = node;
        *phead= node;
    }
}

void remove_node2(listNode* remove)
{

    listNode* y = (listNode*)malloc(sizeof(listNode));
    if(y==NULL)
        return;
    y=remove->link;
    remove->data = y->data;
    remove->link = y->link;
    free(y);
}



void main(){


    listNode * l1=NULL;
    insert_last(&l1, create_node(5, NULL));
     insert_last(&l1, create_node(4, NULL));
     insert_last(&l1, create_node(3, NULL));
     insert_last(&l1, create_node(2, NULL));
     insert_last(&l1, create_node(1, NULL));
    
    display(l1);
    remove_node2(l1);
    display(l1);

    

}