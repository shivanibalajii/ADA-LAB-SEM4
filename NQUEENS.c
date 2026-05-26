#include <stdio.h>

int x[10], n;

int place(int k, int i)
{
    int j;

    for(j = 1; j < k; j++)
    {
        if(x[j] == i || abs(x[j] - i) == abs(j - k))
        {
            return 0;
        }
    }

    return 1;
}

void nQueens(int k)
{
    int i, j;

    for(i = 1; i <= n; i++)
    {
        if(place(k, i))
        {
            x[k] = i;

            if(k == n)
            {
                printf("\nSolution:\n");

                for(i = 1; i <= n; i++)
                {
                    for(j = 1; j <= n; j++)
                    {
                        if(x[i] == j)
                        {
                            printf("Q ");
                        }
                        else
                        {
                            printf(". ");
                        }
                    }
                    printf("\n");
                }
            }
            else
            {
                nQueens(k + 1);
            }
        }
    }
}

int main()
{
    printf("Enter number of queens: ");
    scanf("%d", &n);

    nQueens(1);

    return 0;
}
