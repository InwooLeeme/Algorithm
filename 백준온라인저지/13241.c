
// 13241번 최소 공배수 (실버 3)

#include <stdio.h>

long long int gcd(long long int n1, long long int n2)
{
    if (n2 == 0)
        return n1;
    return gcd(n2, n1 % n2);
}

int main()
{

    long long int a = 0, b = 0;
    scanf("%lld %lld", &a, &b);
    long long int temp = gcd(a, b);
    printf("%lld\n", temp * (a / temp) * (b / temp));

    return 0;
}