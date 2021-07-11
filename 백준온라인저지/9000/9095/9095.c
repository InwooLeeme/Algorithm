#include <stdio.h>
#define size 12

int dp[size] = {
    0,
};

int main()
{
    int t = 0;
    scanf("%d", &t);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= size; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    for (int i = 0; i < t; i++)
    {
        int n = 0;
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }
    return 0;
}