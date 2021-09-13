#include <stdio.h>

int gcd(int n1, int n2)
{
    if (n2 == 0)
        return n1;
    else
        return gcd(n2, n1 % n2);
}

int lcd(int n1, int n2, int gcd)
{
    int x = n1 / gcd;
    int y = n2 / gcd;
    return gcd * x * y;
}

int main()
{
    int a, b, temp = 1;
    int gcdValue, lcdValue;
    scanf("%d %d", &a, &b);
    gcdValue = gcd(a, b); // 최대 공약수
    lcdValue = lcd(a, b, gcdValue);
    printf("%d\n", gcdValue);
    printf("%d\n", lcdValue);
    return 0;
}