/**
 * @file graphUsingAdjacencyMatrix.c
 * @brief To represent a Bi-directional graph using adjacency matrix in C.
 */

#include <stdio.h>

// Initializing the number of vertices
#define vertices 5

/**
 * @brief To add edge between two vertices
 * @param arr the graph representation using matrix
 * @param i represents the position of vertex that has edge with j
 * @param j represents the position of vertex that has edge with i
 */
void addEdge(int arr[][vertices], int i, int j)
{
    if (i < vertices && j < vertices)
    {
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
