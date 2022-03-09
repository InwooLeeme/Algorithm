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
template <typename T>
using max_heap = priority_queue<T>;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

const double INF = 1e9 + 7;

int32_t main(){
	fastio;
	int t; cin >> t;
	while(t--){
		int n,m; cin >> n >> m;
		vector<pair<double, int>> adj[10001];
		while(m--){
			int a,b;
			double c;
			cin >> a >> b >> c;
			adj[a].push_back({c, b});
			adj[b].push_back({c, a});
		}
		vector<double> dist(n, INF);
		// dijk
		min_heap<pair<double, int>> PQ;
		dist[0] = 1;
		PQ.push({dist[0], 0});
		while(!PQ.empty()){
			auto [cost, cur] = PQ.top(); PQ.pop();
			if(dist[cur] < cost) continue;
			for(auto [ncost, nxt] : adj[cur]){
				if(dist[nxt] > ncost * cost){
					dist[nxt] = ncost * cost;
					PQ.push({dist[nxt], nxt});
				}
			}
		}
		cout << fixed << setprecision(10) << dist[n - 1] << "\n";
	}
}