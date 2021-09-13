// 11653번 : 소인수분해(실버 4)

#include <stdio.h>

void divideToPrimeNumber(int n)
{
    for (int i = 2; i <= n; i++)
    {
        while (n % i == 0)
        {
            printf("%d\n", i);
            n /= i;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    divideToPrimeNumber(n);
    return 0;
}