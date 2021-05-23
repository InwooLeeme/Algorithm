// 10103번 : 주사위 게임

#include <stdio.h>

int main()
{
    int n, cy = 100, sk = 100; // cy : 창영, sk : 상덕
    scanf("%d", &n);
    while (n--)
    {
        int a, b; // a : 창영, b : 상덕
        scanf("%d%d", &a, &b);
        if (a > b)
        {
            sk -= a;
        }
        else if (a == b)
        {
            continue;
        }
        else
        {
            cy -= b;
        }
    }
    printf("%d\n%d", cy, sk);
    return 0;
}