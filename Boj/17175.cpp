// 17175번 : 피보나치는 지겨웡~

#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MOD 1000000007
#define MAX 51
using namespace std;

ll dp[MAX];

int main()
{
    fastio;
    int n;
    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2] + 1) % MOD; // 자기 자신을 호출하기 때문에 1을 더해준다.
    }
    cout << dp[n];
    return 0;
}