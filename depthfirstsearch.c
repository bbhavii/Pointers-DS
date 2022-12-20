#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <graph.c>
#include <stacks.c>

/*
DFS or Depth First Search is a technique that traverses a graph along all the adges of a vertices first and then moves on to
other vertices.

For example: If vertice 0 has edges with 1, which has an edge with 2 and 3, then DFS stores the vertices in a queue.

First we print 0, then we can print any of 1, and then either 2 or 3. Let us say we start with 3, then we would back track
until we reach 1, which has an unvisited node, which we then print, 2.

This uses a basic stack structure but no stacks codes has been used.

*/


int visited[] = {0,0,0,0,0};

void DFS(GraphAddress g,int i){

    printf("%d",i);
    visited[i] = 1;
    for(int j=0;j<5;j++){
        if(!visited[j]==1 && HasEdge(g,i,j)){
            DFS(g,j);
        }
    }
}

int main(){


    GraphAddress g = CreateGraph(5);
    AddEdge(g,0,0);
    AddEdge(g,0,1);
    AddEdge(g,1,0);
    AddEdge(g,0,2);
    AddEdge(g,2,0);
    AddEdge(g,1,2);
    AddEdge(g,2,1);
    AddEdge(g,2,3);
    AddEdge(g,3,2);
    AddEdge(g,4,1);
    AddEdge(g,1,4);

    PrintGraph(g);

    DFS(g,0);

    return 0;
}