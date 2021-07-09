// 14494번 : 다이나믹이 뭐예요?(DP 실버 2)

#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 1001
#define ll long long
using namespace std;

ll dp[MAX][MAX];
ll mod = 1e9 + 7;

int main()
{
    fastio;
    int n, m;
    cin >> n >> m;
    dp[1][1] = 1; // 초기 출발 지점의 값을 1로 설정함
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // dp배열이 전역변수로 선언되어 있으면 0으로 자동 초기화가 되므로 초기 값인 dp[1][1]의 값이 1이기 때문에 0이면 점화식을 사용해서 값을 정의해준다.
            if (dp[i][j] != 1)
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1]) % mod;
            }
        }
    }
    cout << dp[n][m];
    return 0;
}