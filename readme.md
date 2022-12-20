# Graphs

This project creates graphs. It adds and removes edges from existing graphs and can check for existence of edges between two nodes.
It explores breadth-first search and depth-first search.
It then checks for cycles within the same graph.
Finally it prints the minimum distance from a node to every other node in the graph using Dijkstra's algorithm.

## graphs.c

This is the first program and the main code.
The function CreateGraph() is used to make the graph. The method used here can be 
Functions AddEdge() and RemoveEdge() are used to manipulate the graph. 
Function HasEdge() checks whether there is an edge or not.
Function PrintGraph() prints the graph.

To construct a directed graph, you must create a graph and store it in a graph address. Then you can add an edge in the desired direction with the source to the end. To construct an undirected graph you must create a graph and store it in a graph address like so, and then add an edge in either direction:
```C
GraphAddress g = CreateGraph(2);
AddEdge(g,0,1);
AddEdge(g,1,0);
PrintGraph(g,2);
```

This is printed as:

```
graph{
edge 0->1
edge 1->0
}
```
We thus construct several graphs.

## Breadth-First Search

We use queues to implement this. The code for queues came from previously uploaded GitHub code. BFS or Breadth First Search is a technique that traverses a graph along all the edges of a vertice first and then moves on to
other vertices.

For example: If vertice 0 has edges with 1,2 and 3, then BFS stores the vertices in a queue. First, we print 0, then we can print any of 1,2, or 3. Let us say we start with 3, then 2 and 1. We would print 3,2,1 and then all
the nodes that 3 is connected to, after which all the nodes that 2 is connected with, and so on.

We test this with a graph of 5 nodes. This graph begins at 0 and is connected to 1 which is connected to 2 which is to 3, and 1 is connected to 4. The 4 should be printed before 3 since we are exploring the breadth of node 1 which is connected to both 2 and 4. The output is thus like so:

```
01243
```
## Depth-First Search

This uses a basic stack structure but no stack codes has been used. DFS or Depth First Search is a technique that traverses a graph along all the adges of a vertices first and then moves on to other vertices.

For example: If vertice 0 has edges with 1, which has an edge with 2 and 3, then DFS stores the vertices in a queue. First, we print 0, then we can print any of 1, and then either 2 or 3. Let us say we start with 3, then we would backtrack until we reach 1, which has an unvisited node, which we then print, 2.

We test this using a graph of 5 nodes. The edges are as follows:
0-1-2-3, and 1-4. This is an undirected graph. The 3 should print before the 4 since we go to the last node until all visited nodes are along the edges of 0, then we backtrack to find other unvisited nodes.  The output is as follows:
```
01234
```

## Finding Cycles

We can find cycles in graphs by checking for edges that lead to already visited nodes. This is done using the DFS or stacks method. The program keeps track of the parent node and whether the edge line originated, and then the edges are followed. If returned to the parent, then there is a cycle.

We test this using a graph of 5 nodes. The edges are as follows:
0-1-2-3, and 1-4. This does not contain a cycle. The output is as follows:

```
That the graph has a cycle is false.
```
We also test using another graph of 5 nodes. The edges are as follows:
0-1-2-3-4, and 1-3. This contains a cycle. The output is as follows:

```
That the graph has a cycle is true.
``` 
## Finding the Shortest Path

This code takes a graph and a starting node and then calculates the shortest path to the other nodes. Several paths are created to measure for the one that is the shortest, which is then stored in a distance array.

The input is a graph as follows of 8 nodes:
0-1-2-3-4-5-7, and 0-7 and 2-6-5. Let us take 0 as the node of choice. The output is as follows:
```
The shortest distance is: 
 0,1,2,3,3,2,3,1
```
Here the distance between any two nodes is 1. From node 0 to 0 the distance is 0. To node 1 is the distance is 1 since it is directly connected. To node 2, it is 2 since it is indirectly connected and has to go through 1, and so on.

## Run the code!

You too can run the code by creating your own directed or undirected graph and find the several paths, cycles, and shortest distances within it.
If you want n nodes, here is the basic code you can insert in the main after invoking the other c files:

```
int n = your_desired_node_count;
GraphAddress g = CreateGraphs(n);
AddEdge(g,source_node,end_node);
AddEdge(g,source_node,end_node);
PrintGraph(g);
bool cycle = UndirectedCycle(g,g->n);
dijkstra(g,source_node);
```