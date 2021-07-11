// 시간 초과 코드
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0, x = 0, count = 0;
    int *list;
    scanf("%d", &n);
    list = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &list[i]);
    }
    scanf("%d", &x);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (x == list[i] + list[j])
            {
                count++;
            }
        }
    }
    printf("%d", count / 2);
    free(list);
    return 0;
}