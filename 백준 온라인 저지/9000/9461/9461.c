// 9461번 : 파도반 수열

#include <stdio.h>
#define size 101

long dp[size];

int main()
{
    int t = 0;
    dp[0] = dp[1] = dp[2] = 1;
    dp[3] = dp[4] = 2;
    dp[5] = 3;
    dp[6] = 4;
    dp[7] = 5;
    dp[8] = 7;
    scanf("%d", &t);
    for (int i = 10; i <= size; i++)
    {
        dp[i - 1] = dp[i - 2] + dp[i - 6];
    }
    for (int i = 0; i < t; i++)
    {
        int n = 0;
        scanf("%d", &n);
        printf("%ld\n", dp[n - 1]);
    }
    return 0;
}