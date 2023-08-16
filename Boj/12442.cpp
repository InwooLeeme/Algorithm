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
		vector<p> G[n + 2];
		while(m--){
			int c,a; cin >> c >> a;
			vi s(a); for(auto& i : s) cin >> i;
			for(int i = 1; i < a; i++){
				G[s[i - 1]].push_back({c, s[i]});
				G[s[i]].push_back({c, s[i - 1]});
			}
		}
		auto Dijkstra = [&](int s) -> vector<int>{
			vector<int> dist(n + 2, INF);
			priority_queue<p, vector<p>, greater<>> PQ;
			dist[s] = 0;
			PQ.push({dist[s], s});
			while(PQ.size()){
				auto [cost, cur] = PQ.top(); PQ.pop();
				if(dist[cur] < cost) continue;
				for(auto [ncost, nxt] : G[cur]){
					if(dist[nxt] > ncost + cost){
						PQ.push({dist[nxt] = ncost + cost, nxt});
					}
				}
			}
			return dist;
		};
		vvi dist(n + 2); 
		for(auto& [s, val] : v) dist[s] = Dijkstra(s);
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
