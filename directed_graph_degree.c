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

void degree(int graph[N][N]){
    int inDegree[N] = {0};
    int outDegree[N] = {0};

    for(int i = 0;i < N; i++){
        for(int j = 0;j < N; j++){
            if(graph[i][j] == 1){
                outDegree[i]++;
                inDegree[j]++;
            }
        }
    }
     for (int i = 0; i < N; i++) {
        printf("%d. node's in-degree: %d, out-degree: %d\n", i + 1, inDegree[i], outDegree[i]);
    }
}

int main(){
int graph[N][N] = {0};

//directed graph
graph[0][2] = 1;
graph[1][3] = 1;
graph[2][1] = 1;
graph[2][3] = 1;
graph[3][2] = 1;

adjacency_matrix(graph);
degree(graph);

return 0;
}