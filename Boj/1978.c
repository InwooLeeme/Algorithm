#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPrimeNumber(int x)
{
    if (x == 1)
        return false;
    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n = 0, prim = 0;
    scanf("%d", &n);
    int *input = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        scanf("%d", &input[i]);
        if (isPrimeNumber(input[i]))
        {
            prim++;
        }
    }
    printf("%d", prim);
    free(input);
    return 0;
}