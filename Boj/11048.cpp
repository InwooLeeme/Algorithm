#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int board[1001][1001], dp[1001][1001];

int main()
{
    fastio;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> board[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + board[i][j];
        }
    cout << dp[n][m] << "\n";
    return 0;
}