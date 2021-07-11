// 11441번 : 합 구하기

#include <stdio.h>
#define MAX 100001

int list[MAX];
int sum[MAX];

int main()
{
    int n, m;
    scanf("%d", &n);
    for (int i = 1; i < n + 1; i++)
    {
        scanf("%d", &list[i]);
        sum[i] = list[i] + sum[i - 1]; //누적 합
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int start, end;
        scanf("%d%d", &start, &end);
        printf("%d\n", sum[end] - sum[start - 1]);
    }
    return 0;
}