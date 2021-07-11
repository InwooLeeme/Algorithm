// 2460번 : 지능형 기차2

#include <stdio.h>

int main()
{
    int a = 0, b = 0, left = 0, max = 0;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d %d", &a, &b);
        left = left - a + b;
        if (max < left)
        {
            max = left;
        }
    }
    printf("%d\n", max);
    return 0;
}