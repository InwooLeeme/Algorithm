#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/rope>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using namespace __gnu_cxx;

#define X first
#define Y second
#define int int64_t
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define Compress(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define OOB(x, y) ((x) < 0 || (x) >= n || (y) < 0 || (y) >= m)
#define IDX(v, x) (lower_bound(all(v), x) - (v).begin())
#define debug(x) cout << (#x) << ": " << (x) << '\n'

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using tii = tuple<int, int, int>;
template <typename T>
using wector = vector<vector<T>>;

vector<int> adj[100001];
int n, m, r;

vector<int> bfs(int st)
{
    vector<int> dist(n + 1, -1), v(n + 1, 0);
    queue<int> Q;
    dist[st] = 0;
    int idx = 1;
    Q.push(st);
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        v[cur] = idx++;
        for (auto &nxt : adj[cur])
        {
            if (dist[nxt] != -1 || nxt < 1 || nxt > n)
                continue;
            Q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }
    return v;
}

int32_t main()
{
    fastio;
    cin >> n >> m >> r;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        sort(all(adj[i]), greater<>());
    auto dist = bfs(r);
    for (int i = 1; i <= n; i++)
        cout << (dist[i] == -1 ? 0 : dist[i]) << "\n";
}