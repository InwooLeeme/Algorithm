#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
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
	int t; cin >> t;
	struct I{ int s, ax, ay, bx, by, fin; };
	while(t--){
		int n; cin >> n;
		vector<vector<int>> g(n + 1);
		vector<int> par(n + 1, -1), vist(n + 1);
		vector<I> v(n);
		for(int i = 0; i < n; i++){
			int h,m; char _;
			cin >> h >> _ >> m >> v[i].ax >> v[i].ay >> v[i].bx >> v[i].by;
			v[i].s = {h * 60 + m};
			v[i].fin = abs(v[i].ax - v[i].bx) + abs(v[i].ay - v[i].by) + v[i].s;
		}
		// add edge
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				auto cur = abs(v[i].bx - v[j].ax) + abs(v[i].by - v[j].ay);
				if(v[i].fin + cur + 1 <= v[j].s){
					g[i].push_back(j);
				}
			}
		}
		auto dfs = [&](int cur, auto&& dfs) -> int{
			for(const auto& nxt : g[cur]){
				if(vist[nxt]) continue;
				vist[nxt] = 1;
				if(par[nxt] == -1 or dfs(par[nxt], dfs)){
					par[nxt] = cur;
					return 1;
				}
			}
			return 0;
		};
		int res = 0;
		for(int i = 0; i < n; i++){
			fill(vist.begin(), vist.end(), 0);
			res += dfs(i, dfs);
		}
		cout << n - res << "\n";
	}
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}
