//
//  main.c
//  dfs_adjacent_list
//
//  Created by Minjeong's Mac on 2016. 11. 6..
//  Copyright (c) 2016년 Minjeong's Mac. All rights reserved.
//

#include <stdio.h>
#define MAX_VERTICES 50
#define TRUE 1
#define FALSE 0
int visited[MAX_VERTICES];

typedef struct GraphNode{

    int vertex;
    struct GraphNode* link;
}GraphNode;

typedef struct GraphList{

    int n;
    GraphNode* list[MAX_VERTICES];
}GraphList;

void init(GraphList *g)
{
    int i;
    g->n = 0;
    for(i=0;i<MAX_VERTICES;i++)
        g->list[i]=NULL;

}


void insert_vertex(GraphList *g)
{

    if(((g->n)+1)>MAX_VERTICES)
    {
        fprintf(stderr, "error");
        return;
    }

    g->n++;
}

void insert_edge(GraphList *g,int start,int end)
{

    GraphNode *new_node = (GraphNode*)malloc(sizeof(GraphNode));
    
    if(g->n<=start || g->n<=end){
        fprintf(stderr, "error");
    return;
    }
    
    
    new_node -> vertex = end;
    new_node->link = g->list[start];
    g->list[start] = new_node;
    
}

void dfs_list(GraphList *g , int v)
{
    GraphNode * w;
    visited[v]=TRUE;
    printf("%d",v);
    
    for(w = g->list[v];w;w=w->link)
        if(!visited[w->vertex])
            dfs_list(g, w->vertex);
    }

void main(){}


