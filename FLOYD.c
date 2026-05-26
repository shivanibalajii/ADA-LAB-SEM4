#include <stdio.h>

int main()
{
    int n, i, j, k;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[n][n];

    printf("Enter cost matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    for(k = 0; k < n; k++)
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(cost[i][k] + cost[k][j] < cost[i][j])
                {
                    cost[i][j] = cost[i][k] + cost[k][j];
                }
            }
        }
    }

    printf("All Pair Shortest Path Matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d ", cost[i][j]);
        }
        printf("\n");
    }

    return 0;
}
