#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <graph.c>


/*
BFS or Breadth First Search is a technique that traverses a graph along all the adges of a vertices first and then moves on to
other vertices.

For example: If vertice 0 has edges with 1,2 and 3, then BFS stores the vertices in a queue.

First we print 0, then we can print any of 1,2 or 3. Let us say we start with 3, then 2 and 1. We would print 3,2,1 and then all
the nodes that 3 is connected to, after which all the nodes that 2 is connected with and so on.

The queue structure is taken from the GitHub.

*/

struct queueType{
    int * data;
    int size;
    int start;
    int n; //no. of elements in the queue
};

typedef struct queueType * QueueAddress;

QueueAddress initQueue(){
    QueueAddress q = malloc(sizeof(struct queueType));
    q->n = 0;
    q->start = -1;
    q->size = 100;
    q->data = malloc(q->size*sizeof(int));
    return q;
}

void freeQueue(QueueAddress q){
    free(q);
}

int insertQueue(QueueAddress q, int val){
    if(q->n==(q->size)){
     return -1; //says queue is full
    }
    q->data[q->start + q->n++] = val;
    return val;
}

int extractQueue(QueueAddress q){
    if(q->n<1) return -1;
    q->n--;
    return q->data[q->start++];
}

int isEmpty(QueueAddress q){
    if(q->n<1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(QueueAddress q){
    if(q->n==q->size){
        return 1;
    }
    else{
        return 0;
    }
}

int visited[5] = {0,0,0,0,0};

void bfsearch(GraphAddress g, int init){

    QueueAddress bfs = initQueue();
    visited[init] = 1;
    printf("%d", init);
    insertQueue(bfs,init);
    while(!isEmpty(bfs)){
        int node = extractQueue(bfs);
        for(int j=0;j<5;j++){
            if(HasEdge(g,node,j) && visited[j]==0){
                printf("%d",j);
                visited[j]=1;
                insertQueue(bfs,j);
            }
        }
    }

    freeQueue(bfs);

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


    
    int init=0;
    bfsearch(g,init);
    
    return 0;
}