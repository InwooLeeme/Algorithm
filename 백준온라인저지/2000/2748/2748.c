
// 90번째 피보나치의 수는 int형으로 표현할 수 없는 큰 수이다.

#include <stdio.h>

int fibo(int n)
{
    if (n < 2)
    {
        return n;
    }
    else
    {
        int i;
        long long num1 = 0, num2 = 1;
        unsigned long result = 0;
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
    printf("%lu", fibo(n));
    return 0;
}