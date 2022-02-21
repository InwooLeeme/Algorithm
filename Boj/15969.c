// 15969번 : 행복

#include <stdio.h>
#include <stdlib.h>

int arr[1001];

int compare(const void *a, const void *b)
{
    int A = *(int *)a;
    int B = *(int *)b;
    if (A > B)
    {
        return 1;
    }
    else
    {
        return -1;
    }
    return 0;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &arr[i]);
    }
    qsort(arr, t, sizeof(int), compare);
    printf("%d", arr[t - 1] - arr[0]);
    return 0;
}