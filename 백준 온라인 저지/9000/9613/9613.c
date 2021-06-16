// 9613번 : GCD 합

#include <stdio.h>
#include <stdlib.h>
#define ll long long

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

ll divide(int n, int list[])
{
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            else
            {
                sum += gcd(list[i], list[j]);
            }
        }
    }
    return sum;
}

int main()
{
    int test;
    scanf("%d", &test);
    while (test--)
    {
        int n;
        scanf("%d", &n);
        int *list;
        list = (int *)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &list[i]);
        }
        printf("%lld\n", divide(n, list) / 2);
        free(list);
    }
    return 0;
}