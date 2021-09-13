// 10178번 : 할로윈의 사탕

#include <stdio.h>

int main()
{
    int test;
    scanf("%d", &test);
    for (int i = 0; i < test; i++)
    {
        int c, v;
        scanf("%d%d", &c, &v);
        printf("You get %d piece(s) and your dad gets %d piece(s).\n", c / v, c % v);
    }
    return 0;
}