#include <stdio.h>

int main()
{
    int m, n, count = 1;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            printf("%d", count);
            if (j != m)
            {
                printf(" ");
            }
            count++;
        }
        printf("\n");
    }
}