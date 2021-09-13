#include <stdio.h>
#define size 1000001

const long long mod = 1000000009;

long long dp[size];

int main()
{
    long long n, test;
    scanf("%lld", &test);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i < size; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % mod;
    }
    for (int i = 0; i < test; i++)
    {
        scanf("%lld", &n);
        printf("%lld\n", dp[n]);
    }
    return 0;
}