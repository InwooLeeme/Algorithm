// 5576번 : 콘테스트

#include <stdio.h>
#include <stdlib.h>
#define size 10

int k[size], w[size];

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
    int sumK = 0, sumW = 0;
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &w[i]);
    }
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &k[i]);
    }
    qsort(k, size, sizeof(int), compare);
    qsort(w, size, sizeof(int), compare);
    for (int i = 7; i < size; i++)
    {
        sumK += k[i];
        sumW += w[i];
    }
    printf("%d %d", sumW, sumK);
    return 0;
}