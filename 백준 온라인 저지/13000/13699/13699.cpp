// 13699번 : 점화식(DP 실버 4)

#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define MAX 36
using namespace std;

ll dp[MAX];

int main()
{
    fastio;
    int n;
    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 5;
    for (int i = 4; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            dp[i] += (dp[j] * dp[i - (j + 1)]);
        }
    }
    cout << dp[n];
    return 0;
}