#include <stdio.h>

int costMatrix[20][20], n;
int i, j, k;
struct router
{
    int distance[20];
    int nextHop[20];
} node[20];

void readCostMatrix()
{
    printf("Enter cost matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &costMatrix[i][j]);

            if (i == j)
            {
                costMatrix[i][j] = 0;
            }
            node[i].distance[j] = costMatrix[i][j];
            node[i].nextHop[j] = j;
        }
    }
}

void calcRoutingTable()
{
    for (int l = 0; l < n; l++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                for (k = 0; k < n; k++)
                {
                    if (node[i].distance[k] + node[k].distance[j] < node[i].distance[j])
                    {
                        node[i].distance[j] = node[i].distance[k] + node[k].distance[j];
                        node[i].nextHop[j] = k;
                    }
                }
            }
        }
    }
}

void displayRoutes()
{
    for (i = 0; i < n; i++)
    {
        printf("\n Router %d\n", i + 1);

        for (j = 0; j < n; j++)
        {
            printf("Node %d via %d | distance %d", j + 1, node[i].nextHop[j] + 1, node[i].distance[j]);
            printf("\n");
        }
    }
}

int main()
{
    printf("Enter no of nodes: ");
    scanf("%d", &n);

    readCostMatrix();
    calcRoutingTable();
    displayRoutes();

    return 0;
}