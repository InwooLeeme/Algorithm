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

struct TwoSAT{
	int n,c,scc_cnt;
	vector<vector<int>> adj;
	vector<int> disc,scc;
	stack<int> S;
	TwoSAT(int n = 0):
		n(n),c(0),disc((n << 1) + 1, 0),scc_cnt(0),
		scc((n << 1) + 1, 0),adj((n << 1) + 1){}
	
	int DFS(int cur){
		S.push(cur);
		disc[cur] = ++c;
		int ret = disc[cur];
		for(auto nxt : adj[cur]){
			if(!disc[nxt]) ret = min(ret, DFS(nxt));
			else if(!scc[nxt]) ret = min(ret, disc[nxt]);
		}
		if(ret == disc[cur]){
			scc_cnt++;
			while(S.size()){
				int h = S.top(); S.pop();
				scc[h] = scc_cnt;
				if(h == cur) break;
			}
		}
		return ret;
	}
	int cvt(int x){ return (x <= n ? x + n : x - n); }
	
	void AddEdge(int a,int b){
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	bool isSatisified(){
		for(int i = 1; i <= n << 1; i++){
			if(!disc[i]) DFS(i);
		}
		for(int i = 1; i <= n; i++){
			if(scc[i] == scc[cvt(i)]) return false;			
		}
		return true;
	}
};

void Main(){
	int t; cin >> t;
	for(int tc = 1; tc <= t; tc++){
		cout << "Scenario #" << tc << ":\n";
		int n,m; cin >> n >> m;
		TwoSAT G(n); while(m--){
			int a,b; cin >> a >> b;
			G.AddEdge(a, G.cvt(b)); G.AddEdge(b, G.cvt(a)); G.AddEdge(G.cvt(b), a); G.AddEdge(G.cvt(a), b);
		}
		cout << (!G.isSatisified() ? "Suspicious bugs found!" : "No suspicious bugs found!") << "\n";
		cout << "\n";
	}
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
	return 0;
}
