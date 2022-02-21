#include <stdio.h>
#define size 5001
#define min(a, b) ((a < b) ? a : b)

int dp[size];

int main()
{
    int n = 0, result = 0;
    scanf("%d", &n);
    while (1)
    {
        if (n % 5 != 0)
        {
            n -= 5;
            if (n < 0)
                break;
        }
        else if (n % 3 != 0)
        {
            n -= 3;
            if (n < 0)
                break;
        }
    }
    printf("%d\n", result);
    return 0;
}