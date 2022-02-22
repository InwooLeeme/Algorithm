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
vector<pii> adj[1001];
vector<int> dist(1001, INF);

int32_t main(){
	fastio;
	int n,m,a,b; cin >> n >> m;
	while(m--){
		int u,v,w; cin >> u >> v >> w;
		adj[u].push_back({w, v});
	}
	cin >> a >> b;
	priority_queue<pii,vector<pii>,greater<pii>> PQ;
	dist[a] = 0;
	PQ.push({dist[a], a});
	while(!PQ.empty()){
		auto [cost, cur] = PQ.top(); PQ.pop();
		if(dist[cur] < cost) continue;
		for(auto [ncost, nxt] : adj[cur]){
			if(dist[nxt] > ncost + cost){
				dist[nxt] = ncost + cost;
				PQ.push({dist[nxt], nxt});
			}
		}
	}
	cout << dist[b] << "\n";
}