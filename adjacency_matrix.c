#include <stdio.h>

#define N 4 
//this is an adjacency matrix for 4 vertices.

void adjacency_matrix(int graph[N][N]){
    for(int i = 0; i < N;i++){
        for(int j = 0; j < N ;j++){
            printf("%d ",graph[i][j]);
        }
    printf("\n");
    }
}

int main(){
int graph[N][N] = {0};

//undirected graph
graph[0][2] = 1;
graph[1][2] = 1;
graph[1][3] = 1;
graph[2][0] = 1;
graph[2][1] = 1;
graph[2][3] = 1;
graph[3][1] = 1;
graph[3][2] = 1;

adjacency_matrix(graph);

printf("\n");

// Reset graph for directed graph
 for (int i = 0; i < N; i++) {
           for (int j = 0; j < N; j++) {
            graph[i][j] = 0;
        }
    }

//directed graph
graph[0][2] = 1;
graph[1][3] = 1;
graph[2][1] = 1;
graph[2][3] = 1;
graph[3][2] = 1;

adjacency_matrix(graph);

return 0;
}