#include <stdio.h>

int main()
{
    int n, i, j, capacity;
    float totalProfit = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[n], profit[n];
    float ratio[n];

    printf("Enter weights:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &weight[i]);
    }

    printf("Enter profits:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &profit[i]);
        ratio[i] = (float)profit[i] / weight[i];
    }

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(ratio[j] < ratio[j + 1])
            {
                float tempRatio = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = tempRatio;

                int tempWeight = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = tempWeight;

                int tempProfit = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = tempProfit;
            }
        }
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    for(i = 0; i < n; i++)
    {
        if(weight[i] <= capacity)
        {
            totalProfit += profit[i];
            capacity -= weight[i];
        }
        else
        {
            totalProfit += ratio[i] * capacity;
            break;
        }
    }

    printf("Maximum profit = %.2f\n", totalProfit);

    return 0;
}
