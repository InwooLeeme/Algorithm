#include <stdio.h>

int main()
{
    int result = 0, sum = 0;
    scanf("%d", &result);
    for (int i = 0; i < 9; i++)
    {
        int a = 0;
        scanf("%d", &a);
        sum += a;
    }
    printf("%d\n", result - sum);
}