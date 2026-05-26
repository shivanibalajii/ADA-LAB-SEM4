#include <stdio.h>

int main()
{
    int n, i, j, source, min, u;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[n][n], distance[n], visited[n];

    printf("Enter cost matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    for(i = 0; i < n; i++)
    {
        distance[i] = cost[source][i];
        visited[i] = 0;
    }

    visited[source] = 1;
    distance[source] = 0;

    for(i = 0; i < n - 1; i++)
    {
        min = 999;

        for(j = 0; j < n; j++)
        {
            if(visited[j] == 0 && distance[j] < min)
            {
                min = distance[j];
                u = j;
            }
        }

        visited[u] = 1;

        for(j = 0; j < n; j++)
        {
            if(visited[j] == 0 && distance[u] + cost[u][j] < distance[j])
            {
                distance[j] = distance[u] + cost[u][j];
            }
        }
    }

    printf("Shortest distances from vertex %d:\n", source);

    for(i = 0; i < n; i++)
    {
        printf("%d -> %d = %d\n", source, i, distance[i]);
    }

    return 0;
}
