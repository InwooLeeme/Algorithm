#include <stdio.h>

int main()
{
    int i, j, N = 0;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        for (j = N - i - 1; j > 0; j--)
        {
            printf(" ");
        }
        for (j = 0; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}