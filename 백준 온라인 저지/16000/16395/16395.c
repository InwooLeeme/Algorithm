// 16395번 : 파스칼의 삼각형
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

double fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * fact(n - 1);
}

double combi(int n, int k)
{
    return fact(n) / (fact(k) * fact(n - k));
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%.lf", combi(n - 1, k - 1));
    return 0;
}