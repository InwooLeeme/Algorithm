// 11051번 : 이항 계수 2

#include <stdio.h>
#define mod 10007
#define MAX 1001

int dp[MAX][MAX];

void fibo(int n, int k)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (i == j || j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
            }
        }
    }
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    fibo(n, k);
    printf("%d\n", dp[n][k]);
    return 0;
}