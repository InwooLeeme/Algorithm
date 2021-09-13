// 1330번 : 두 수 비교하기

#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    if (a > b)
    {
        printf(">\n");
    }
    else if (a == b)
    {
        printf("==\n");
    }
    else
    {
        printf("<\n");
    }
    return 0;
}