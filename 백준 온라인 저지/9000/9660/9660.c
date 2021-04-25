#include <stdio.h>

int main()
{
    unsigned long long n = 0;
    scanf("%llu", &n);
    if (n % 7 == 2 || n % 7 == 0)
    {
        printf("CY");
    }
    else
    {
        printf("SK");
    }
    return 0;
}