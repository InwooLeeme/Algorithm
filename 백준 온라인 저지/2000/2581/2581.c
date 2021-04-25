#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPrimNumber(int n)
{
    if (n == 1)
        return false;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int m = 0, n = 0, sum = 0, min = 0, count = 0;
    scanf("%d %d", &m, &n);
    int *findMin;
    findMin = (int *)malloc(sizeof(int) * (n - m));
    for (int i = m; i <= n; i++)
    {
        if (isPrimNumber(i) == true)
        {
            sum += i;
            findMin[count] = i;
            count++;
        }
    }
    min = findMin[0];
    if (count == 0)
    {
        printf("-1");
    }
    else
    {
        printf("%d\n", sum);
        printf("%d\n", min);
    }
    return 0;
}