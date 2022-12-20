#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct graph{
    // needs a number of nodes
    int n;

    //2d array or adjacency matrix to store the graph
    bool **edge;
};

typedef struct graph * GraphAddress;


void FreeGraph(GraphAddress g){
    if(g->edge==NULL){
        return;
    }
    for(int i=0;i<g->n;i++){
        if(g->edge[i]!=NULL){
            free(g->edge[i]);
        }
    }
    free(g->edge);
    free(g);
}

GraphAddress CreateGraph(int n){
    //allocating memory to the graph
    GraphAddress g = malloc(sizeof(g));

    //checking for memory allocation
    if (g==NULL){
        return NULL;
    }
    //allocating the number of nodes
    g->n = n;
    
    //allocating the edges for g and initialising as 0
    //each edge is an array 
    g->edge = calloc(sizeof(bool*),g->n);
    //making sure tha the edge was allocated with memory
    if(g->edge==NULL){
        free(g);
        return NULL;
    }

    //each edge has its own connectors stored as an array
    //thus the whole graph is an n*n matrix for n as total edges
    for(int i=0; i<g->n;i++){
        g->edge[i]=calloc(sizeof(bool*),g->n);
        if(g->edge==NULL){
        FreeGraph(g);
        return NULL;
        }
    }
    return g;
}

bool HasEdge(GraphAddress g, int from, int to){
    //making sure things are going fine
    assert(g != NULL);
    assert(from<g->n);
    assert(to<g->n);
    
    return g->edge[from][to];
}

bool AddEdge(GraphAddress g, int from, int to){
    //making sure things are going fine
    assert(g != NULL);
    assert(from<g->n);
    assert(to<g->n);
    
    if(HasEdge(g,from,to)){
        return false;
    }
    
    g->edge[from][to]=true;
}

bool RemoveEdge(GraphAddress g, int from, int to){
    //making sure things are going fine
    assert(g != NULL);
    assert(from<g->n);
    assert(to<g->n);
    
    if(!HasEdge(g,from,to)){
        return false;
    }
    g->edge[from][to] = false;
}

void PrintGraph(GraphAddress g){
    printf("graph {\n");

    for(int i=0;i<g->n;i++){
        for(int j=0;j<g->n;j++){
            if(g->edge[i][j]){
                printf("edge %d->%d \n",i,j);
            }
        }
    }

    printf("}\n");
}

int main(){

    GraphAddress g = CreateGraph(3);
    AddEdge(g,0,0);
    AddEdge(g,0,1);
    AddEdge(g,0,2);
    AddEdge(g,1,2);
    AddEdge(g,2,1);
    PrintGraph(g);

    return 0;
}