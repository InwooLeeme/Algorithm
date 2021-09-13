// 14284번 : 간선 이어가기 2

#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define MAX 5001
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

vector<pii> adj[MAX];
vector<int> dist(MAX, INF);

void dijk(int start, int end)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int weight = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (cur == end)
            return;
        if (dist[cur] < weight)
            continue;
        for (int i = 0; i < adj[cur].size(); i++)
        {
            int next = adj[cur][i].second;
            int nWeight = adj[cur][i].first;
            if (dist[next] > nWeight + weight)
            {
                dist[next] = nWeight + weight; // 가중치 갱신
                pq.push({dist[next], next});
            }
        }
    }
}

int main()
{
    fastio;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({w, v});
        adj[v].pb({w, u});
    }
    int s, t;
    cin >> s >> t;
    dijk(s, t);
    cout << dist[t] << "\n";
    return 0;
}