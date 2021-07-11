// 9658번 : 돌 게임 4

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    if (n % 7 == 1 || n % 7 == 3)
    {
        printf("CY\n");
    }
    else
    {
        printf("SK\n");
    }
    return 0;
}