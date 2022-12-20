#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <graph.c>
#include <breadthfirstsearch.c>
#include <depthfirstsearch.c>


bool DFS(GraphAddress g,int n,int i, int parent,int visited[]){

    visited[i] = 1;
    for(int j=0;j<n;j++){
        if(HasEdge(g,i,j)){
            if(j==parent){
                continue;
            }
            if(visited[j]==1){
                return true;
            }
            if(DFS(g,n,j,i,visited)){
                return true;
            }
        }
    }
    return false;
}


bool UndirectedCycle(GraphAddress g, int n){
    
    int visited[5] = {0,0,0,0,0};
    
    for(int i =0;i<n;i++){
    
        if(visited[i]==0 && DFS(g,n,i,-1,visited)){
            return true;
        }
        
    }

    return false;
}

int main(){
    
    GraphAddress g = CreateGraph(5);
    AddEdge(g,0,1);
    AddEdge(g,1,0);
    AddEdge(g,1,2);
    AddEdge(g,2,1);
    AddEdge(g,2,3);
    AddEdge(g,3,2);
    AddEdge(g,1,4);
    AddEdge(g,4,1);


    
    int n=5;
    bool cycle=UndirectedCycle(g,5);
    
    printf("That the graph has a cycle is %s", cycle?"true":"false" );
    return 0;
}