// 14495번 : 피보나치 비스무리한 수열(DP 실버 3)
#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define MAX 117
using namespace std;

ll dp[MAX];

int main()
{
    fastio;
    int n;
    cin >> n;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i < MAX; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 3];
    }
    cout << dp[n];
    return 0;
}