#include <stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    printf("%s", (n % 2 == 0) ? "SK" : "CY");
    return 0;
}