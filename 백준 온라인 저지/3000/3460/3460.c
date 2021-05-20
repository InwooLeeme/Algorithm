// 3460번 : 이진수

#include <stdio.h>

int main(void)
{
    int t, n;

    scanf("%d", &t);

    while (t--)
    {
        scanf("%d", &n);
        int c = 0;
        while (n != 0)
        {
            if (n % 2 == 1)
                printf("%d ", c);
            n /= 2;
            c++;
        }
        printf("\n");
    }

    return 0;
}