//
//  main.c
//  adjacent_matrix_adjacant_list
//
//  Created by Minjeong's Mac on 2016. 11. 6..
//  Copyright (c) 2016년 Minjeong's Mac. All rights reserved.
//

#include <stdio.h>

#define MAX_VERTICES 50

typedef struct GraphType{
    int n;
    int add_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType_matrix;


typedef struct GraphNode{
    int vertex;
    struct GraphNode* link;
}GraphNode;

typedef struct GraphType_List{
    int n;
    GraphNode* list[MAX_VERTICES];
}GraphType_list;



void init_matrix(GraphType_matrix *g)
{
    int i,j;
    g->n =0;
    for(i=0;i<MAX_VERTICES;i++)
        for(j=0;j<MAX_VERTICES;j++)
            g->add_mat[i][j]=0;
}


void init_list(GraphType_list *g)
{
    int i;
    g->n=0;
    for(i=0;i<MAX_VERTICES;i++)
        g->list[i]=NULL;
}


void insert_vertex_matrix(GraphType_matrix *g)
{

    if((g->n+1)>MAX_VERTICES){
        fprintf(stderr, "ERROR");
        return;}
    g->n++;
}

void insert_vertex_list(GraphType_list *g)
{

    if((g->n+1)>MAX_VERTICES)
    {
        fprintf(stderr, "ERROR");
        return;
    }
    g->n++;
}

void insert_edge_matrix(GraphType_matrix *g, int start, int end)
{


    if(start>=g->n || end>=g->n)
    {
    
        fprintf(stderr,"error");
        return;
    }
    
    g->add_mat[start][end] = 1;
    g->add_mat[end][start]=1;
}


void insert_edge_list(GraphType_list *g, int start, int end){


    GraphNode *new_node = (GraphNode*)malloc(sizeof(GraphNode));
    
    if(start>=g->n||end>=g->n)
    {
        fprintf(stderr, "error");
        return;
    }
    
    new_node -> vertex = end;
    new_node -> link = g->list[start];
    g->list[start] = new_node;
}

void main(){
    
    int i;
    GraphType_list list1;
    init_list(&list1);
    for(i=0;i<4;i++)
        insert_vertex_list(&list1);
    insert_edge_list(&list1, 0, 1);
    insert_edge_list(&list1, 1, 0);
    insert_edge_list(&list1, 0, 3);
    insert_edge_list(&list1, 3, 0);
    insert_edge_list(&list1, 1, 2);
    insert_edge_list(&list1, 2, 1);
    insert_edge_list(&list1, 1, 3);
    insert_edge_list(&list1, 3, 1);
    insert_edge_list(&list1, 2, 3);
    insert_edge_list(&list1, 3, 2);
    
    
    GraphType_matrix matrix1;
    init_matrix(&matrix1);
    for(i=0;i<4;i++)
        insert_vertex_matrix(&matrix1);
    insert_edge_matrix(&matrix1, 0, 1);
    insert_edge_matrix(&matrix1, 0, 3);
    insert_edge_matrix(&matrix1, 1, 2);
    insert_edge_matrix(&matrix1, 1, 3);
    insert_edge_matrix(&matrix1, 2, 3);
    
    




}
