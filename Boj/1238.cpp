// 1238번 : 파티
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

vector<pii> adj[1001];
int n,m,x; 
const int INF = 1e9 + 7;

vector<int> dijk(int st){
	vector<int> dist(n + 1, INF);
	priority_queue<pii,vector<pii>,greater<pii>> PQ;	
	dist[st] = 0;
	PQ.push({dist[st], st});
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
	return dist;
}

int32_t main(){
	fastio;
	cin >> n >> m >> x;
	while(m--){
		int a,b,c; cin >> a >> b >> c;
		adj[a].push_back({c, b});
	}
	auto dist1 = dijk(x); // x -> i
	int mx = 0;
	for(int i = 1; i <= n; i++){
		auto dist2 = dijk(i);
		int t1 = dist1[i],t2 = dist2[x]; // t1 : x -> i, t2 : i -> x
		mx = max(mx, t1 + t2);
	}
	cout << mx << "\n";
}