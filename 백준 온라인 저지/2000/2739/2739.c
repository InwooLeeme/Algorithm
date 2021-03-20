#include <stdio.h>

int main()
{
    int i, j, N;
    scanf("%d", &N);
    for (i = N; i <= N; i++)
    {
        for (j = 1; j <= 9; j++)
        {
            printf("%d * %d = %d\n", i, j, i * j);
        }
    }
    return 0;
}