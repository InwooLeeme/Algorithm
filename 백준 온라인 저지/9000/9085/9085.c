// 9085번 : 더하기

#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n = 0, sum = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            int num;
            scanf("%d", &num);
            sum += num;
        }
        printf("%d\n", sum);
    }
    return 0;
}