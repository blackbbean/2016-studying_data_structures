//
//  main.c
//  heap
//
//  Created by Minjeong's Mac on 2016. 12. 10..
//  Copyright (c) 2016년 Minjeong's Mac. All rights reserved.
//

#include <stdio.h>
#define MAX_ELEMENT 200

typedef struct{

    int key;
}element;

typedef struct{

    element heap[MAX_ELEMENT];
    int heap_size;
}HeapType;

void init(HeapType *h)
{


    h->heap_size = 0;
}

void insert_max_heap(HeapType *h,element item){

    int i;
    i = ++(h->heap_size);
    
    while((i!=1)&&(item.key>h->heap[i/2].key)){
        h->heap[i] = h->heap[i/2];
        i/=2;
    }
    h->heap[i]=item;

}


element delete_max_heap(HeapType *h)
{

    int parent,child;
    element item,temp;
    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    while(child<=h->heap_size)
    {
    
        if((child<h->heap_size)&&
           (h->heap[child].key)<h->heap[child+1].key)
            child++;
        if(temp.key >= h->heap[child].key)
            break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

int find(HeapType *h, int item)
{
    int i = 1;
    while(i<=h->heap_size){
    
        if(h->heap[i].key==item)
            break;
        else
            i++;
    }

    if(i==h->heap_size+1)
    {
    
        printf("no item");
        return -1;
    }

    printf("find success");
    return item;


}



void main(){

    element e1 = {10};
    element e2 = {5};
    element e3 = {30};
    element e4 = {89};
    element e5 = {102};
    element e6 = {37};
    element e7,e8,e9;
    
    HeapType h1;
    init(&h1);
    insert_max_heap(&h1,e1);
    insert_max_heap(&h1,e2);
    insert_max_heap(&h1,e3);
    insert_max_heap(&h1,e4);
    insert_max_heap(&h1,e5);
    insert_max_heap(&h1,e6);
    e7 = delete_max_heap(&h1);
    printf("%d\n",e7.key);
    e8 = delete_max_heap(&h1);
    printf("%d\n",e8.key);
    e9 = delete_max_heap(&h1);
    printf("%d\n",e9.key);

    int a =find(&h1,10);
    printf("%d",a);
}
