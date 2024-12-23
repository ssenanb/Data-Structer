#include <stdio.h>
#include <stdlib.h>

#define N 4

struct node{
    int vertex;
    struct node *next ;
};

typedef struct node graph;

graph *adjacency_list[N];

graph *newNode(int vertex){
    graph *newNode = (graph*)malloc(sizeof(graph));
    newNode -> vertex = vertex;
    newNode -> next = NULL; 
    return newNode;
}

void addEdge(int src,int dest){
    graph *node = newNode(dest);
    node -> next = adjacency_list[src];
    adjacency_list[src] = node;
}
//src is a node,dest is an edge.
//for example : assume src = 2, dest = 1; adding 1 node in adjacency_list[2] 

void display(){
    for(int i = 0;i < N; i++){
        printf("%d: ", i);
        graph *temp = adjacency_list[i];
    while(temp != NULL){
        printf("%d ",temp -> vertex);
        temp = temp -> next;
        }
    printf("\n");
    }
}
//task of the display function is display all the neighbour.


int main(){
    for(int i = 0; i < N ;i++){
        adjacency_list[i] = NULL;
    }

    addEdge(0,2);
    addEdge(1,2);
    addEdge(1,3);
    addEdge(2,1);
    addEdge(2,3);
    addEdge(3,1);
    addEdge(3,2);

    display();
    return 0;
}