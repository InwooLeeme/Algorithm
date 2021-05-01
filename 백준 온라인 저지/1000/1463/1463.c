#include <stdio.h>
#define size 1000001
#define MIN(a, b) ((a < b) ? a : b)

int main()
{
    int dp[size];
    int k = 0;
    scanf("%d", &k);
    dp[1] = 0;
    for (int i = 2; i <= k; i++)
    {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0)
        {
            dp[i] = MIN(dp[i], dp[i / 2] + 1);
        }
        if (i % 3 == 0)
        {
            dp[i] = MIN(dp[i], dp[i / 3] + 1);
        }
    }
    printf("%d\n", dp[k]);
    return 0;
}