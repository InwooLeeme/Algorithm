// 19532번 : 수학은 비대면강의입니다
#include <stdio.h>
#define Msize -999
#define size 999

int main()
{
    int a, b, c, d, e, f;
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
    for (int i = Msize; i <= size; i++)
    {
        for (int j = Msize; j <= size; j++)
        {
            if (a * i + b * j == c && d * i + e * j == f)
            {
                printf("%d %d", i, j);
                break;
            }
        }
    }
    return 0;
}