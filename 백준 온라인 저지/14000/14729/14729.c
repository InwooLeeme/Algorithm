// 14729번 : 칠무해

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    float A = *(float *)a;
    float B = *(float *)b;
    if (A > B)
    { // 오름차순 정렬
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
    int n;
    scanf("%d", &n);
    float *list;
    list = (float *)malloc(sizeof(float) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &list[i]);
    }
    qsort(list, n, sizeof(float), compare);
    for (int i = 0; i < 7; i++)
    {
        printf("%.3f\n", list[i]);
    }
    free(list);
    return 0;
}