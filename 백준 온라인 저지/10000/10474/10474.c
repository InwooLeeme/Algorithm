// 10474번 : 분수 좋아해?

#include <stdio.h>

int main()
{
    while (1)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a == 0 && b == 0)
        {
            break;
        }
        printf("%d %d / %d\n", a / b, a % b, b);
    }
    return 0;
}