// Adjacency Matrix representation in C
#include <stdio.h>
#define vertices 5

void addEdge(int arr[][vertices], int i, int j)
{
    if(i<vertices && j< vertices){
        arr[i][j] = 1;
        arr[j][i] = 1;
    }
    else
        printf("Node not found\n");
}

int main()
{
    int adjMatrix[vertices][vertices];
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            adjMatrix[i][j] = 0;

    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 2);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 2, 0);
    addEdge(adjMatrix, 2, 3);
    addEdge(adjMatrix, 4, 3);

    printf("Adjacency Matrix representation of graph:\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
            printf("%d ", adjMatrix[i][j]);
        printf("\n");
    }
    return 0;
}
