// 1005번 : ACM Craft

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

int main()
{
    fastio;
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k, w;
        cin >> n >> k;
        vector<int> indegree(n), time(n), dp(n);
        vi adj[1001];
        queue<int> q;
        for (int i = 0; i < n; i++)
            cin >> time[i];
        for (int i = 0; i < k; i++)
        {
            int a, b;
            cin >> a >> b;
            --a, --b;
            indegree[b]++;
            adj[a].pb(b);
        }
        for (int i = 0; i < n; i++)
        {
            if (!indegree[i])
            {
                dp[i] = time[i];
                q.push(i);
            }
        }
        cin >> w;
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
        cout << dp[--w] << "\n";
    }
    return 0;
}