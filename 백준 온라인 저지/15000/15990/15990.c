// 15990번 : 1,2,3더하기 5

#include <stdio.h>
#define MAX 100001
#define mod 1000000009
#define ll long long

ll dp[MAX][4]; // 0번 인덱스를 사용하지 않기 위해서 4로 선언

ll getSum(int n)
{
    for (int i = 4; i < MAX; i++)
    {
        dp[i][1] = ((dp[i - 1][2] + dp[i - 1][3]) % mod);
        dp[i][2] = ((dp[i - 2][1] + dp[i - 2][3]) % mod);
        dp[i][3] = ((dp[i - 3][1] + dp[i - 3][2]) % mod);
    }
    return (dp[n][1] + dp[n][2] + dp[n][3]) % mod;
}

int main()
{
    int test;
    scanf("%d", &test);
    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;
    while (test--)
    {
        int x;
        scanf("%d", &x);
        printf("%lld\n", getSum(x));
    }
    return 0;
}