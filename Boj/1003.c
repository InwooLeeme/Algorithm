// 1003번 : 피보나치 함수 3

#include <stdio.h>
#define MAX 41

int dp[MAX][2] = {
    {1, 0},
    {0, 1},
};

void fibo(int n)
{
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
        dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
    }
}

int main()
{
    int test;
    scanf("%d", &test);
    while (test--)
    {
        int n;
        scanf("%d", &n);
        fibo(n);
        printf("%d %d\n", dp[n][0], dp[n][1]);
    }
    return 0;
}