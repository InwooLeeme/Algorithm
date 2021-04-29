#include <stdio.h>
#define size 1000

long long dp[size];

int main()
{
    dp[0] = 2;
    dp[1] = 4;
    int n = 0;
    scanf("%d", &n);
    for (int i = 2; i <= size; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    printf("%lld\n", dp[n]);
    return 0;
}