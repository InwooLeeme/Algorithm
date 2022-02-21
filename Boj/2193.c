// 2193번 : 이친수

#include <stdio.h>
#define size 91

long long dp[size];

int main()
{
    int n = 0;
    scanf("%d", &n);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= size; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    printf("%lld\n", dp[n]);
    return 0;
}