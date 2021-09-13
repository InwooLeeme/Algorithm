// 1149번 : RGB거리(DP 실버 1)

#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#define max 1001
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int dp[max][3];
int input[max][3];

int main()
{
    fastio;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> input[i][j];
        }
    }
    dp[1][0] = input[1][0];
    dp[1][1] = input[1][1];
    dp[1][2] = input[1][2];
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + input[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + input[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + input[i][2];
    }
    int result = 1e9;
    for (int i = 0; i < 3; i++)
    {
        if (dp[n][i] < result)
        {
            result = dp[n][i];
        }
    }
    printf("%d\n", result);
    return 0;
}