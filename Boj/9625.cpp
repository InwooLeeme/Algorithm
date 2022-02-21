// 9625번 : BABBA

#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <math.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define max 46
#define mod 1000000000
using namespace std;

int dp[max][3] = {{1, 0, 1}, {0, 1, 1}, {1, 1, 2}};

int main()
{
    fastio;
    int k;
    cin >> k;
    for (int i = 2; i < max; i++)
    {
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][2] = dp[i][0] + dp[i][1];
    }
    printf("%d %d\n", dp[k][0], dp[k][1]);
    return 0;
}