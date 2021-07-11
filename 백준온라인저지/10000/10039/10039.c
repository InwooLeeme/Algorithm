#include <stdio.h>

int main()
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        int a = 0;
        scanf("%d", &a);
        if (a < 40)
        {
            a = 40;
        }
        sum += a;
    }
    printf("%d\n", sum / 5);
    return 0;
}