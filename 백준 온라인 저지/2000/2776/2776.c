// 2776번 : 암기왕

#include <stdio.h>
#include <stdlib.h>
#define max 1000001

int su1[max];

void BinarySearch(int target, int n)
{
    int start = 0;
    int end = n - 1;
    while ((end - start) >= 0)
    {
        int mid = (end + start) / 2;
        if (su1[mid] == target)
        {
            printf("1\n");
            return;
        }
        else if (target > su1[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    printf("0\n");
    return;
}

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
    int test;
    scanf("%d", &test);
    while (test--)
    {
        int n, m;
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &su1[j]);
        }
        qsort(su1, n, sizeof(int), compare);
        scanf("%d", &m);
        for (int j = 0; j < m; j++)
        {
            int target;
            scanf("%d", &target);
            BinarySearch(target, n);
        }
    }
    return 0;
}