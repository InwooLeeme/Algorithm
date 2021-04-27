#include <stdio.h>

int main()
{
    int a = 0;
    int i = 0, count = 0;
    while (scanf("%d", &a) == 1)
    {
        count += a;
    }
    printf("%d", count);
    return 0;
}