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

vector<int> adj[1000001];
int dx[] = {-1,1};

int32_t main(){
	fastio;
	int a,b,n,m; cin >> a >> b >> n >> m;
	vector<int> dist(100001, -1);
	dist[n] = 0;
	queue<int> Q;
	Q.push(n);
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		for(int i = 0; i < 2; i++){
			auto nx = cur + dx[i];
			if(nx < 0 || nx > 100000 || dist[nx] != -1) continue;
			dist[nx] = dist[cur] + 1;
			Q.push(nx);
		}
		for(auto& nxt : {cur + a, cur - a, cur + b, cur - b, cur * a, cur * b}){
			if(nxt < 0 || nxt > 100000 || dist[nxt] != -1) continue;
			dist[nxt] = dist[cur] + 1;
			Q.push(nxt);
		}
	}
	cout << dist[m] << "\n";
}