/* 
재귀로 된 풀이 : 시간초과
#include <stdio.h>

int fibo(int n)
{
    int a1 = 0, a2 = 1, a3 = 0;
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return (fibo(n - 2) + fibo(n - 1));
    }
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    int result = fibo(n);
    printf("%d", result);
    return 0;
}
 */

// 2. 반복을 이용한 풀이

#include <stdio.h>

int fibo(int n)
{
    int i, num1 = 0, num2 = 1, result = 0;
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
    }
    return result;
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    printf("%d", fibo(n));
    return 0;
}