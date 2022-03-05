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

int n,m,x,y,z;
const int INF = 1e9 + 7;
vector<pii> adj[100001];

vector<int> dijk(int st){ // cross y
	vector<int> dist(n + 1, INF);
	priority_queue<pii,vector<pii>,greater<pii>> PQ;
	dist[st] = 0;
	PQ.push({dist[st], st});
	while(!PQ.empty()){
		auto [cost, cur] = PQ.top(); PQ.pop();
		if(dist[cur] < cost) continue;
		for(auto& [ncost, nxt] : adj[cur]){
			if(dist[nxt] > ncost + cost){
				dist[nxt] = ncost + cost;
				PQ.push({dist[nxt], nxt});
			}
		}
	}
	return dist;
}

vector<int> dijk2(int st){ // not cross y
	vector<int> dist(n + 1, INF);
	priority_queue<pii,vector<pii>,greater<pii>> PQ;
	dist[st] = 0;
	PQ.push({dist[st], st});
	while(!PQ.empty()){
		auto [cost, cur] = PQ.top(); PQ.pop();
		if(dist[cur] < cost) continue;
		for(auto& [ncost, nxt] : adj[cur]){
			if(nxt == y) continue;
			if(dist[nxt] > ncost + cost){
				dist[nxt] = ncost + cost;
				PQ.push({dist[nxt], nxt});
			}
		}
	}
	return dist;
}

int32_t main(){
	fastio;
	cin >> n >> m;
	while(m--){
		int a,b,c; cin >> a >> b >> c;
		adj[a].push_back({c, b});
	}
	cin >> x >> y >> z;
	auto t1 = dijk(x),t2 = dijk(y);
	int ret1 = t1[y],ret2 = t2[z];
	auto dist = dijk2(x);
	if(ret1 == INF || ret2 == INF) cout << -1 << " ";
	else cout << ret1 + ret2 << " ";
	cout << (dist[z] == INF ? -1 : dist[z]) << "\n";
}