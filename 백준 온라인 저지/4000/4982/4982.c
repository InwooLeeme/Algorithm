// 4982번 : 숫자 맞추기

#include <stdio.h>

int main()
{
    int n0, n1, n2, n3, n4;
    int i = 1;
    while (1)
    {
        scanf("%d", &n0);
        if (n0 == 0)
            break;
        n1 = 3 * n0;
        if (n1 % 2 == 0)
        {
            n2 = n1 / 2;
        }
        else
        {
            n2 = (n1 + 1) / 2;
        }
        n3 = 3 * n2;
        n4 = n3 / 9;
        if (n1 % 2 == 0)
        {
            printf("%d. even %d\n", i, n4);
        }
        else
        {
            printf("%d. odd %d\n", i, n4);
        }
        i++;
    }
    return 0;
}