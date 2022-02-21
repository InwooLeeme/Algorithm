// 1934번 : 최소 공배수
#include <stdio.h>

int gcd(int n1, int n2)
{
    if (n2 == 0)
        return n1;
    return gcd(n2, n1 % n2);
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        int temp = gcd(a, b);
        printf("%d\n", temp * (a / temp) * (b / temp));
    }
    return 0;
}