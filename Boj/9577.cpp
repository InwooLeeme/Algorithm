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
vector<int> g[1111];
vector<int> par(1111, -1);
vector<bool> match(1111);

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

int Matching(){
	int ret = 0;
	for(int i = 0; i <= 1001; i++){
		fill(match.begin(), match.end(), 0);
		ret += DFS(i);
		if(ret == n){
			return i + 1;
		}
	}
	return -1;
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   	int t; cin >> t;
   	while(t--){
		fill(par.begin(), par.end(), -1);
		for(int i = 0; i < 1111; i++) g[i].clear();
		cin >> n >> m;
		for(int i = 1; i <= m; i++){
			int a,b,c; cin >> a >> b >> c;
			while(c--){
				int t; cin >> t;
				for(int j = a; j < b; j++) g[j].push_back(t);
			}
		}
		cout << Matching() << "\n";
	}
    return 0; 
}
