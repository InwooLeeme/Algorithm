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

vector<int> adj[100001],adj2[100001];
int n,m,t; 

int32_t main(){
	fastio;
	cin >> n >> m;
	vector<bool> vist1(n + 1,false),vist2(n + 1, false);
	while(m--){
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		adj2[b].push_back(a);
	}
	// 1 -> n bfs
	queue<int> Q;
	vist1[1] = true;
	Q.push(1);
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		for(auto nxt : adj[cur]){
			if(nxt < 1 || nxt > n || vist1[nxt]) continue;
			vist1[nxt] = true;
			Q.push(nxt);
		}
	}
	// n -> 1 bfs
	queue<int> Q1;
	vist2[n] = true;
	Q1.push(n);
	while(!Q1.empty()){
		auto cur = Q1.front(); Q1.pop();
		for(auto nxt : adj2[cur]){
			if(nxt < 1 || nxt > n || vist2[nxt]) continue;
			vist2[nxt] = true;
			Q1.push(nxt);
		}
	}
	// query
	cin >> t;
	while(t--){
		int x; cin >> x;		
		cout << ((vist1[x] && vist2[x]) ? "Defend the CTP\n" : "Destroyed the CTP\n");
	}
}