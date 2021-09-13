// 2455번 : 지능형 기차

#include <stdio.h>

int main()
{
    int a, b, left = 0, max = 0; // left : 남은 사람수, max : 최댓값
    for (int i = 0; i < 4; i++)
    {
        scanf("%d%d", &a, &b);
        left = left + b - a;
        if (max < left)
        {
            max = left;
        }
    }
    printf("%d\n", max);
    return 0;
}