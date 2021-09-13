// 10282번 : 해킹

#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define MAX 10001
#define INF 1e9
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using dbl = double;
using ldb = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
#define sz(a) int((a).size())

int main()
{
    fastio;
    int tc;
    cin >> tc;
    while (tc--)
    {
        int start = 0;
        pii ans;
        vector<pii> adj[MAX];
        int n, d, c;
        cin >> n >> d >> c; // n : 컴퓨터 개수, d : 의존성 개수, c : 컴퓨터의 번호(시작 정점)
        start = c;
        ans.second = 0, ans.first = -1;
        for (int i = 0; i < d; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[v].pb({w, u});
        }
        vector<int> dist(MAX, INF);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        dist[start] = 0;
        pq.push({0, start});
        while (!pq.empty())
        {
            int weight = pq.top().first;
            int cur = pq.top().second;
            pq.pop();
            if (dist[cur] < weight)
                continue;
            for (auto i = 0; i < adj[cur].size(); i++)
            {
                int next = adj[cur][i].second;
                int nWeight = adj[cur][i].first;
                if (dist[next] > nWeight + weight)
                {
                    dist[next] = nWeight + weight;
                    pq.push({dist[next], next});
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] != INF)
            {
                ans.second++;
                ans.first = max(ans.first, dist[i]);
            }
        }
        cout << ans.second << ' ' << ans.first << "\n";
    }
    return 0;
}