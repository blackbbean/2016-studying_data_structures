//
//  main.c
//  single_linked_list_alternate
//
//  Created by Minjeong's Mac on 2016. 10. 21..
//  Copyright (c) 2016년 Minjeong's Mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Listnode{
    element data;
    struct Listnode * link;
}Listnode; //struct that define listnode

void error(char *message)
{
   fprintf(stderr,"%s\n",message);
    exit(1);
}   // define error function


void insert_node(Listnode **phead,Listnode *p,Listnode *new_node)
{
    if(*phead==NULL) //when the list is blank
    {
        *phead = new_node;
        new_node->link = NULL;
    }
    else if(p == NULL) // trying to insert node in first position
    {   
        new_node->link = *phead;
        *phead = new_node;
    }
    else{
        new_node->link = p->link;
        p->link = new_node;
    }
} //insert node function


void remove_node(Listnode **phead,Listnode *p,Listnode *removed)
{
    if(p==NULL)
        *phead = (*phead)->link;
    else
        p->link = removed->link;
    free(removed);
} //remove the node

void display(Listnode *head)
{
    Listnode * p = head;
    while( p != NULL){
        printf("%d->",p->data);
        p=p->link;
    }
    printf("\n");
} //display the node


Listnode *create_node(element data, Listnode *link)
{
    Listnode * new_node;
    new_node = (Listnode *)malloc(sizeof(Listnode));
   if(new_node == NULL)
       error("memory alloction error");
    new_node -> data = data;
    new_node -> link = link;
    return(new_node);
}

Listnode* alternate_list(Listnode *l1, Listnode *l2)
{
    Listnode *p_l1 = l1;
    Listnode *p_l2 = l2;
    Listnode *l3 = NULL;
    Listnode *p_l3 = l3;
   
    
 
    
    if(l3==NULL)
    {
        insert_node(&l3, NULL, create_node(p_l1->data, NULL));
        p_l1 = p_l1 -> link;
    
        
        insert_node(&l3, p_l3, create_node(p_l2->data, NULL));
        p_l2 = p_l2 -> link;
        p_l3 = l3->link;
        
    
    }
 

    while(p_l1!=NULL && p_l2!=NULL)
    {
        
        
            insert_node(&l3, p_l3, create_node(p_l1->data, NULL));
            p_l1 = p_l1 -> link;
        p_l3 = p_l3->link;
        
            insert_node(&l3, p_l3, create_node(p_l2->data, NULL));
            p_l2 = p_l2 -> link;
        
        p_l3 = p_l3->link;
        
        
    
        
        }
    
    
    if(p_l1 == NULL)
    {    while(p_l2!=NULL)
        {insert_node(&l3, p_l3, create_node(p_l2->data, NULL));
        p_l2 = p_l2 -> link;
         p_l3 = p_l3->link;
        }
    
    }
    else if(p_l2==NULL)
        while(p_l1!=NULL)
        {insert_node(&l3,p_l3, create_node(p_l1->data, NULL));
            p_l1 = p_l1 -> link;
        
        p_l3 = p_l3->link;
        }
    
    return l3;
}



void main(int argc, const char * argv[]) {
 
    Listnode *list1 = NULL;
    Listnode *list2 = NULL;

    
    insert_node(&list1, NULL, create_node(10,NULL));
    insert_node(&list1, NULL, create_node(20,NULL));
    insert_node(&list1, NULL, create_node(30,NULL));
    insert_node(&list1, NULL, create_node(40,NULL)); // 40->30->20->10
    
    display(list1);
    insert_node(&list2, NULL, create_node(100,NULL));
    insert_node(&list2, NULL, create_node(200,NULL));
    insert_node(&list2, NULL, create_node(300,NULL));
    insert_node(&list2, NULL, create_node(400,NULL)); //400->300->200->100
   
    display(list2);
    
    
    display(alternate_list(list1, list2));
    


}
