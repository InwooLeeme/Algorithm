// 10991번 : 별찍기 - 16
#include <stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        // 공백
        for (int j = n; j > i; j--)
        {
            printf(" ");
        }

        // 별 찍기
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            if (j % 2 == 0)
            {
                printf(" ");
            }
            else
            {
                printf("*");
            }
        }
        printf("\n");
    }
    return 0;
}
