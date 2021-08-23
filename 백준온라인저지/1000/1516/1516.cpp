// 1516번 : 게임 개발

#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(a) int((a).size())
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
using namespace std;
using ll = long long;
using ull = unsigned long long;
using dbl = double;
using ldb = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using wector = vector<vector<int>>;

vi adj[501];

int main()
{
    fastio;
    int n;
    cin >> n;
    vi dp(n, 0), indegree(n, 0), time(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> time[i];
        while (1)
        {
            int x;
            cin >> x;
            if (x == -1)
                break;
            indegree[i]++;
            adj[--x].pb(i);
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (!indegree[i])
        {
            dp[i] = time[i];
            q.push(i);
        }
    }
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        for (auto nxt : adj[cur])
        {
            dp[nxt] = max(dp[nxt], dp[cur] + time[nxt]);
            if (--indegree[nxt] == 0)
                q.push(nxt);
        }
    }
    for (auto i : dp)
        cout << i << "\n";
    return 0;
}