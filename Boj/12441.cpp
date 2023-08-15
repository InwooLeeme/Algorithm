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
	using p = pair<int, int>;
	using vi = vector<int>; using vvi = vector<vi>;
	constexpr int INF = int(2e18);
	int t; cin >> t; for(int tc = 1; tc <= t; tc++){
		cout << "Case #" << tc << ": ";
		int n,P,m; cin >> n >> P >> m;
		vector<p> v(P); for(auto& [a, b] : v) cin >> a >> b;
		vvi dist(n + 1, vi(n + 1, INF));
		while(m--){
			int c,a; cin >> c >> a;
			vi s(a); for(auto& i : s) cin >> i;
			for(int i = 1; i < a; i++){
				dist[s[i - 1]][s[i]] = min<int>(dist[s[i - 1]][s[i]], c);
				dist[s[i]][s[i - 1]] = min<int>(dist[s[i]][s[i - 1]], c);
			}
		}
		for(int i = 1; i <= n; i++) dist[i][i] = 0;
		// floyd
		for(int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++){
			dist[i][j] = min<int>(dist[i][j], dist[i][k] + dist[k][j]);
		}
		int mn = INF;
		for(int i = 1; i <= n; i++){
			bool flag = 0; int mx = 0;
			for(auto& [s, val] : v){
				if(dist[s][i] == INF){ flag = 1; break;}
				mx = max<int>(mx, (dist[s][i] * val));
			}
			if(flag) continue;
			mn = min<int>(mn, mx);
		}
		cout << (mn == INF ? -1 : mn) << "\n";
	}
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
	return 0;
}
