// 1920번 : 수 찾기

#include <stdio.h>
#include <stdlib.h>

int list[100001];

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

void BinarySearch(int target, int n)
{
    int start = 0;
    int end = n - 1;
    while ((end - start) >= 0)
    {
        int mid = (start + end) / 2;
        if (target == list[mid])
        {
            printf("1\n");
            return;
        }
        // 중간값보다 target값이 더 크면
        else if (target > list[mid])
        {
            start = mid + 1;
        }
        // 중간값보다 target값이 작으면
        else
        {
            end = mid - 1;
        }
    }
    printf("0\n");
    return;
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
    int target;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &target);
        BinarySearch(target, n);
    }
    return 0;
}