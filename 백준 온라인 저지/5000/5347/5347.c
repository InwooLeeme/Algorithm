// LCM : 5347번
#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    int t = 0;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        int large = gcd(a, b);
        printf("%d\n", large * (a / large) * (b / large));
    }
    return 0;
}