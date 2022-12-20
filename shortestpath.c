#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <graph.c>


int MinDistance(int visited[], int dist[]){
    int min=1000;
    int min_index=0;

    for(int v=0;v<8;v++){
        if(visited[v]==0 && dist[v] <= min){
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printDistance(int dist[]){
    printf("The shortest distance is: \n %d",dist[0]);
    for(int i=1;i<8;i++){
        printf(",%d",dist[i]);
    }
}

void dijkstra(GraphAddress g, int i){
    int dist[8] = {1000,1000,1000,1000,1000,1000,1000,1000};
    int visited[8] = {0,0,0,0,0,0,0,0};

    dist[i]=0;

    for(int count=0;count<7;count++){
        int closest = MinDistance(visited,dist);
        visited[closest]=1;
        for(int v=0;v<8;v++){
            if(visited[v]==0 
               && HasEdge(g,closest,v)
               && dist[closest]!= 1000
               && dist[closest] + 1 < dist[v]){
                dist[v] = dist[closest] + 1;
               }

        }
        
    }
    printDistance(dist);

}


int main(){

    GraphAddress g = CreateGraph(8);
    AddEdge(g,0,1);
    AddEdge(g,1,0);
    AddEdge(g,2,1);
    AddEdge(g,1,2);
    AddEdge(g,2,3);
    AddEdge(g,3,2);
    AddEdge(g,3,4);
    AddEdge(g,4,3);
    AddEdge(g,4,5);
    AddEdge(g,5,4);
    AddEdge(g,6,5);
    AddEdge(g,5,6);
    AddEdge(g,2,6);
    AddEdge(g,6,2);
    AddEdge(g,7,5);
    AddEdge(g,5,7);
    AddEdge(g,0,7);
    AddEdge(g,7,0);
    
    dijkstra(g,0);


    return 0;
}