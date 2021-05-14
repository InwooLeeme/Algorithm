// 1789번 : 수들의 합
#include <stdio.h>

long long S = 0;

int main()
{
    scanf("%lld", &S);
    int x = 1;
    while (1)
    {
        if (x * x + x >= 2 * S)
        {
            break;
        }
        x++;
    }
    printf("%d", x - 1);
    return 0;
}