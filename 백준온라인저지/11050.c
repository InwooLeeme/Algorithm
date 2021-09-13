// 110950번 : 이항계수
#include <stdio.h>

int factorial(int n)
{
    int i, result = 1;
    for (i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

int main()
{
    int result = 0, n, k = 0;
    scanf("%d%d", &n, &k);
    result = factorial(n) / (factorial(k) * factorial(n - k));
    printf("%d", result);
    return 0;
}