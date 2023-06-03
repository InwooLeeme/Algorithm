# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#define int int_fast64_t

int n,m;
bool Bound(int x, int y) {return x < 0 or x >= n or y < 0 or y >= m;}
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
vector<bool> match(5555, 0);
vector<int> par(5555, -1);
vector<int> g[5555];
vector<vector<bool>> vist;

int DFS(int cur){
	for(auto nxt : g[cur]){
		if(match[nxt]) continue;
		match[nxt] = 1;
		if(par[nxt] == -1 or DFS(par[nxt])){
			par[nxt] = cur;
			return 1;
		}
	}
	return 0;
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while(cin >> n >> m and n){
		fill(par.begin(), par.end(), -1);
		for(int i = 0; i < 5555; i++) g[i].clear();
		int k; cin >> k;
		vist = vector<vector<bool>>(111, vector<bool>(111));
		while(k--){
			int a,b; cin >> a >> b; --a,--b;
			vist[a][b] = 1;
		}
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
			if(vist[i][j]) continue;
			if(i + j & 1){
				for(int d = 0; d < 4; d++){
					auto nx = i + dx[d], ny = j + dy[d];
					if(Bound(nx, ny) or vist[nx][ny]) continue;
					g[i *m + j].push_back(nx * m + ny);
				}
			}
		}
		int ret = 0;
		for(int i = 0; i < n*m; i++){
			fill(match.begin(), match.end(), 0);
			ret += DFS(i);
		}
		cout << ret << '\n';		
	}
    return 0; 
}
