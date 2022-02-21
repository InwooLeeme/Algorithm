// 9657번 : 돌 게임3

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    if (n % 7 == 0 || n % 7 == 2)
    {
        printf("CY\n");
    }
    else
    {
        printf("SK\n");
    }
    return 0;
}