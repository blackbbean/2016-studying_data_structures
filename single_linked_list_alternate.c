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
}Listnode; //리스트 노드를 정의한 구조체

void error(char *message)
{
    fprintf(stderr,"%s\n",message);
    exit(1);
}   // 에러 함수


void insert_node(Listnode **phead,Listnode *p,Listnode *new_node)
{
    if(*phead==NULL) //연결리스트가 공백일 때
    {
        *phead = new_node;
        new_node->link = NULL;
    }
    else if(p == NULL) //삽입하고자 하는 노드(new_node)가 첫번째 노드 자리로 삽입될 때
    {
        new_node->link = *phead;
        *phead = new_node;
    }
    else{
        new_node->link = p->link;
        p->link = new_node;
    }
} //노드 삽입 함수


void remove_node(Listnode **phead,Listnode *p,Listnode *removed)
{
    if(p==NULL) //연결리스트의 첫번째 노드 삭제 함수
        *phead = (*phead)->link;
    else
        p->link = removed->link;
    free(removed);
} //노드 제거 함수

void display(Listnode *head)
{
    Listnode * p = head;
    while( p != NULL){
        printf("%d->",p->data);
        p=p->link;
    }
    printf("\n");
} //노드 출력 함수

Listnode *create_node(element data, Listnode *link)
{
    Listnode * new_node;
    new_node = (Listnode *)malloc(sizeof(Listnode));
    if(new_node == NULL)
        error("memory alloction error");
    new_node -> data = data;
    new_node -> link = link;
    return(new_node);
} // 노드 생성 함수

Listnode* alternate_list(Listnode *l1, Listnode *l2)
{
    Listnode *p_l1 =l1; //p_l1은 l1을 가르키는 노드
    Listnode *p_l2 = l2; //p_l2는 l2을 가르키는 노드
    Listnode *l3 = NULL; //l3은 alternate함수의 결과를 담을 노드 변수
    Listnode *p_l3 =NULL; //p_l3은 l3을 가르킬 노드
    

    if(l3==NULL) // alternate함수의 결과가 안나왔을 경우
    {
        insert_node(&l3, NULL, create_node(p_l1->data, NULL)); //list1의 첫번째 노드의 data값을 가진 노드 생성후 l3의 첫번째 노드로
        p_l1 = p_l1 -> link; // p_l1은 l1의 두번째 노드 가르킴
        p_l3 = l3; //p_l3을 여기서 정의한 이유는 p_l3은 새로 생길 l3노드의 직전 노드를 가르켜야 하기 때문에.
        
        insert_node(&l3, p_l3, create_node(p_l2->data, NULL)); //list1의 첫번째 노드의 data값을 가진 노드 생성후 l3의 두번째 노드로
        p_l2 = p_l2 -> link;
        p_l3 = l3->link;
    }
    
    
    while(p_l1!=NULL && p_l2!=NULL) //list1과 list2노드를 둘 다 탐색할 수 있을때
    {
        insert_node(&l3, p_l3, create_node(p_l1->data, NULL));
        p_l1 = p_l1 -> link;
        p_l3 = p_l3->link;
        
        insert_node(&l3, p_l3, create_node(p_l2->data, NULL));
        p_l2 = p_l2 -> link;
        p_l3 = p_l3->link;
    }
    
    if(p_l1 == NULL) //만약 list1은 이미 다 탐색했을 경우
    {    while(p_l2!=NULL) //list2의 노드들 다 l3에 붙여준다.
        {
            insert_node(&l3, p_l3, create_node(p_l2->data, NULL));
            p_l2 = p_l2 -> link;
            p_l3 = p_l3->link;
        }
        
    }
    else if(p_l2==NULL) //만약 list2를 이미 다 탐색했을 경우
        while(p_l1!=NULL) //list1의 노드들을 l3에 붙여준다.
        {
            insert_node(&l3,p_l3, create_node(p_l1->data, NULL));
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
    
    printf("list1 :");
    display(list1);
    
    insert_node(&list2, NULL, create_node(100,NULL));
    insert_node(&list2, NULL, create_node(200,NULL));
    insert_node(&list2, NULL, create_node(300,NULL));
    insert_node(&list2, NULL, create_node(400,NULL)); //400->300->200->100
    
    printf("list2 :");
    display(list2);
    
    printf("after alternate :");
    display(alternate_list(list1, list2));
    
    
    
}
