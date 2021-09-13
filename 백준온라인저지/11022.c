#include <stdio.h>

int main()
{
    int t = 0, i;
    scanf("%d", &t);
    for (i = 0; i < t; i++)
    {
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        printf("Case #%d: %d + %d = %d\n", i + 1, a, b, a + b);
    }
    return 0;
}