//10815 숫자 카드

#include <stdio.h>
#include <stdlib.h>

int list[500001];

void BinarySearch(int target, int n)
{
    int start = 0;
    int end = n - 1;
    while ((end - start) >= 0)
    {
        int mid = (end + start) / 2;
        if (list[mid] == target)
        {
            printf("1 ");
            return;
        }
        else if (target > list[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    printf("0 ");
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
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &list[i]);
    }
    qsort(list, n, sizeof(int), compare);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int target;
        scanf("%d", &target);
        BinarySearch(target, n);
    }
    return 0;
}