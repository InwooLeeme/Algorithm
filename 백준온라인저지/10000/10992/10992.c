// 10992번 : 별 찍기 - 17

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    // 첫번째 줄
    for (int i = 0; i < n - 1; i++)
    {
        printf(" ");
    }
    printf("*\n");
    // 2 ~ n - 1번째 줄
    for (int i = 2; i < n; i++)
    {
        //외부 공백
        for (int j = 0; j < n - i; j++)
        {
            printf(" ");
        }
        printf("*");
        //내부 공백
        for (int j = 0; j < 2 * (i - 1) - 1; j++)
        {
            printf(" ");
        }
        printf("* \n");
    }
    // n번째 줄
    if (n != 1)
    {
        for (int i = 0; i < 2 * n - 1; i++)
        {
            printf("*");
        }
    }
    return 0;
}