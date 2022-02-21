// 1977번 : 완전 제곱수

#include <stdio.h>

int main()
{
    int m, n, min = 10000, sum = 0, count = 0;
    scanf("%d%d", &m, &n);
    for (int i = m; i <= n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (j * j == i)
            {
                sum += j * j;
                count++;
                if (min > i)
                {
                    min = i;
                }
            }
        }
    }
    if (count == 0)
    {
        printf("-1");
        return 0;
    }
    else
        printf("%d\n%d", sum, min);
    return 0;
}