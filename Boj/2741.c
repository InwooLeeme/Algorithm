#include <stdio.h>

int main()
{
    int i, number = 0;
    scanf("%d", &number);
    for (i = 1; i <= number; i++)
    {
        printf("%d\n", i);
    }
    return 0;
}