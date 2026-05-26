#include <stdio.h>

int main()
{
    int n, i, j, indegree[10] = {0}, count = 0;
    int graph[10][10], visited[10] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(graph[i][j] == 1)
            {
                indegree[j]++;
            }
        }
    }

    printf("Topological Ordering: ");

    while(count < n)
    {
        for(i = 0; i < n; i++)
        {
            if(indegree[i] == 0 && visited[i] == 0)
            {
                printf("%d ", i);
                visited[i] = 1;
                count++;

                for(j = 0; j < n; j++)
                {
                    if(graph[i][j] == 1)
                    {
                        indegree[j]--;
                    }
                }
            }
        }
    }

    return 0;
}
