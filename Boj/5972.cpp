// 5972번 : 택배 배송

#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define MAX 50001
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

int dijk(int start, int end)
{
    vector<int> dist(MAX, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq; // <가중치,노드>순 구성
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty())
    {
        int weight = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (cur == end)
            return dist[end];
        if (dist[cur] < weight)
            continue;
        for (int i = 0; i < adj[cur].size(); i++)
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
    return INF;
}

int main()
{
    fastio;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({c, b});
        adj[b].pb({c, a});
    }
    cout << dijk(1, n);
    return 0;
}