#include <stdio.h>
#include <time.h>

void merge(int a[], int low, int mid, int high)
{
    int i, j, k;
    int temp[100000];

    i = low;
    j = mid + 1;
    k = low;

    while(i <= mid && j <= high)
    {
        if(a[i] < a[j])
        {
            temp[k] = a[i];
            i++;
        }
        else
        {
            temp[k] = a[j];
            j++;
        }
        k++;
    }

    while(i <= mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }

    while(j <= high)
    {
        temp[k] = a[j];
        j++;
        k++;
    }

    for(i = low; i <= high; i++)
    {
        a[i] = temp[i];
    }
}

void mergeSort(int a[], int low, int high)
{
    int mid;

    if(low < high)
    {
        mid = (low + high) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main()
{
    int n, i;
    clock_t start, end;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    start = clock();

    mergeSort(a, 0, n - 1);

    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted elements:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\nTime taken = %f seconds\n", time_taken);

    return 0;
}
