#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#define int int_fast64_t

const int PRECISION = 0;

void Main(){
	using vi = vector<double>;
	using vvi = vector<vi>;
	constexpr int INF = 2e18;
	struct P{ int a,b,c;};
	auto GetDist = [&](P& a, P& b) -> double{
		return sqrt((a.a - b.a) * (a.a - b.a) + (a.b - b.b) * (a.b - b.b) + (a.c - b.c) * (a.c - b.c));
	};
	int t; cin >> t; for(int tc = 1; tc <= t; tc++){
		int n,m,q; cin >> n;
		unordered_map<string, int> Idx;
		vector<int> x(n + 1),y(n + 1),z(n + 1);
		vvi dist(n + 1, vi(n + 1, INF));
		for(int i = 1; i <= n; i++){
			string s; cin >> s >> x[i] >> y[i] >> z[i];
			Idx[s] = i; 
			for(int j = 1; j < i; j++){
				dist[i][j] = dist[j][i] = sqrt(pow(x[i]-x[j], 2.0) + pow(y[i]-y[j], 2.0) + pow(z[i]-z[j], 2.0));
			}
			dist[i][i] = 0;
		}
		cin >> m;
		while(m--){
			string a,b; cin >> a >> b;
			dist[Idx[a]][Idx[b]] = 0;
		}
		// floyd
		for(int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) dist[i][j] = min<double>(dist[i][j], dist[i][k] + dist[k][j]);
		cout << "Case " << tc << ":\n";
		cin >> q;
		while(q--){
			string s,e; cin >> s >> e;
			cout << "The distance from " << s << " to " << e << " is " << dist[Idx[s]][Idx[e]] << " parsecs.\n";
		}
	}
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
	return 0;
}
