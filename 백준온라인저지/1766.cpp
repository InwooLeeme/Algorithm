// https://www.acmicpc.net/problem/1766

#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define MAX 100001
#define INF 1e9 + 7
#define sz(a) int((a).size())
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
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
    int n, m;
    cin >> n >> m;
    vector<int> adj[32001];
    vector<int> indegree(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].pb(b);
        indegree[b]++;
    }
    vector<int> v;
    priority_queue<int, vi, greater<int>> q;
    for (int i = 0; i < n; i++)
        if (!indegree[i])
            q.push(i);
    while (!q.empty())
    {
        auto cur = q.top();
        q.pop();
        v.pb(cur);
        for (auto nxt : adj[cur])
        {
            if (--indegree[nxt] == 0)
                q.push(nxt);
        }
    }
    for (auto i : v)
        cout << i + 1 << " ";
    cout << "\n";
    return 0;
}