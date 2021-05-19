// 9295번 : 주사위

#include <stdio.h>

int main()
{
    int test, i = 1;
    scanf("%d", &test);
    for (int j = 0; j < test; j++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("Case %d: %d\n", i, a + b);
        i++;
    }
    return 0;
}