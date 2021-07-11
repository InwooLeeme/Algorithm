// 2579번 : 계단 오르기(DP 실버 3)

#include <iostream>
#include <algorithm>
#include <math.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 301
using namespace std;

int dp[MAX]; // dp[i] : i번째 계단까지 올라섰을 때, 밟지 않을 계단의 합의 최솟값, 단 i번째 계단을 반드시 밟지 않을 계단으로 선택
int S[MAX];

// 점화식 : dp[k] = min(dp[k - 3],dp[k - 2]) + S[k];

int main()
{
    fastio;
    int n;
    cin >> n;
    int total = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> S[i];
        total += S[i];
    }
    dp[1] = S[1];
    dp[2] = S[2];
    dp[3] = S[3];
    for (int i = 4; i <= n; i++)
    {
        dp[i] = min(dp[i - 3], dp[i - 2]) + S[i];
    }
    cout << total - min(dp[n - 1], dp[n - 2]); // dp의 식이 밟지 않을 계단으로 정의되었으나 문제의 조건에 따라서 n번째 계단은 반드시 밟아야한다.
    // 따라서 모든 계단의 합을 더한 값에서 가장 마지막으로 선택될 밟지 않을 계단인 n - 1번째 계단이나 n - 2번째 계단의 최솟값을 빼주어야 한다.
    return 0;
}