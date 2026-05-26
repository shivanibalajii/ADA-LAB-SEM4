#include <stdio.h>

void printPermutation(int a[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int getMobile(int a[], int dir[], int n)
{
    int mobile = 0, mobileIndex = -1, i;

    for(i = 0; i < n; i++)
    {
        if(dir[i] == -1 && i != 0 && a[i] > a[i - 1] && a[i] > mobile)
        {
            mobile = a[i];
            mobileIndex = i;
        }

        if(dir[i] == 1 && i != n - 1 && a[i] > a[i + 1] && a[i] > mobile)
        {
            mobile = a[i];
            mobileIndex = i;
        }
    }

    return mobileIndex;
}

int main()
{
    int n, i, j;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n], dir[n];

    for(i = 0; i < n; i++)
    {
        a[i] = i + 1;
        dir[i] = -1;
    }

    printPermutation(a, n);

    while(1)
    {
        int mobileIndex = getMobile(a, dir, n);

        if(mobileIndex == -1)
        {
            break;
        }

        int swapIndex = mobileIndex + dir[mobileIndex];

        int temp = a[mobileIndex];
        a[mobileIndex] = a[swapIndex];
        a[swapIndex] = temp;

        temp = dir[mobileIndex];
        dir[mobileIndex] = dir[swapIndex];
        dir[swapIndex] = temp;

        for(i = 0; i < n; i++)
        {
            if(a[i] > a[swapIndex])
            {
                dir[i] = -dir[i];
            }
        }

        printPermutation(a, n);
    }

    return 0;
}
