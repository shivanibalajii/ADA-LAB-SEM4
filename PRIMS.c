#include <stdio.h>

int main()
{
    int n, i, j, min, u = 0, v = 0, total = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[n][n], visited[n];

    printf("Enter cost matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    for(i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    visited[0] = 1;

    printf("Edges in MST:\n");

    for(i = 0; i < n - 1; i++)
    {
        min = 999;

        for(j = 0; j < n; j++)
        {
            if(visited[j] == 1)
            {
                int k;
                for(k = 0; k < n; k++)
                {
                    if(visited[k] == 0 && cost[j][k] < min)
                    {
                        min = cost[j][k];
                        u = j;
                        v = k;
                    }
                }
            }
        }

        printf("%d - %d = %d\n", u, v, min);
        total += min;
        visited[v] = 1;
    }

    printf("Minimum Cost = %d\n", total);

    return 0;
}
