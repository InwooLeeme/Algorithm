// 10569번 : 다면체

#include <stdio.h>

int main()
{
    int test;
    scanf("%d", &test);
    for (int i = 0; i < test; i++)
    {
        int v, e;
        scanf("%d%d", &v, &e);
        printf("%d\n", 2 - v + e);
    }
    return 0;
}