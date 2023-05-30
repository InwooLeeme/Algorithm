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

// 1 - indexed base // 
struct BM{
	int n;
	vector<vector<int>> adj;
	vector<int> par;
	vector<bool> match;
	
	BM(int n = 0, int m = 0): n(n),adj(n + 1),par(m + 1, -1),match(n + 1, 0){}
	void AddEdge(int a,int b){ adj[a].push_back(b);}
	
	int DFS(int cur){
		for(auto nxt : adj[cur]){
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
		for(int i = 1; i <= n; i++){
			fill(match.begin(), match.end(), 0);
			ret += DFS(i);
		}
		return ret;
	}
};

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n,m;
    while(cin >> n >> m and n){
        vector<int> b(n),r(m);
        for(auto& i : b) cin >> i;
        for(auto& i : r) cin >> i;
        BM G(555, 555);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(__gcd(b[i], r[j]) > 1) G.AddEdge(i + 1, j + 1);
            }
        }
        cout << G.Matching() << "\n";
    }
    return 0; 
}
