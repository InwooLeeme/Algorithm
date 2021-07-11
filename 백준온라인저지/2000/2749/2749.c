
#include <stdio.h>

unsigned long long fibo(unsigned long long n)
{
    long long result = 0, num1 = 0, num2 = 1;
    int i;
    if (n < 2)
    {
        return n;
    }
    else
    {
        for (i = 2; i <= n; i++)
        {
            result = num1 + num2;
            num1 = num2;
            num2 = result;
        }
        return result;
    }
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    printf("%llu\n", fibo(n));
    return 0;
}