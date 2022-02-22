// 1504번 : 특정한 최단 경로

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

const int INF = int(1e9);
int V, E, v1, v2, dist[801];
vector<pii> adj[801];

void Dijkstra(int st) {
	fill(dist + 1, dist + V + 1, INF);
	priority_queue<pii, vector<pii>, greater<pii>> PQ;
	dist[st] = 0;
	PQ.push({ dist[st], st });
	while (!PQ.empty()) {
		auto [cost, idx] = PQ.top(); PQ.pop();
		if (dist[idx] != cost) continue;
		for (auto [ncost, nidx] : adj[idx]) {
			if (dist[nidx] > cost + ncost) {
				dist[nidx] = cost + ncost;
				PQ.push({ dist[nidx], nidx });
			}
		}
	}
}

int main() {
	fastio;
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c; cin >> a >> b >> c;
		adj[b].push_back({ c, a });
		adj[a].push_back({ c, b });
	}
	cin >> v1 >> v2;
	long long temp1 = 0, temp2 = 0;
	Dijkstra(1); temp1 += dist[v1]; temp2 += dist[v2];
	Dijkstra(v1); temp1 += dist[v2]; temp2 += dist[V];
	Dijkstra(v2); temp1 += dist[V]; temp2 += dist[v1];
	if (temp1 >= INF && temp2 >= INF) cout << -1 << '\n';
	else if (temp1 >= INF) cout << temp2 << '\n';
	else if (temp2 >= INF) cout << temp1 << '\n';
	else cout << min(temp1, temp2) << '\n';
}