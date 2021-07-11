// 1547번 : 공

#include <stdio.h>

int main()
{
    int m;
    scanf("%d", &m);
    int ball = 1;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x == ball || y == ball)
        {
            ball = (x == ball ? y : x);
        }
    }
    printf("%d\n", ball);
    return 0;
}