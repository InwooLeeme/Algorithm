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

struct SCC {
	int n, scc_cnt, dfs_cnt;
	vector<vector<int>> adj;
	vector<int> scc, dfs_order;
	stack<int> S;

	SCC(int n) :
		n(n), scc_cnt(0), dfs_cnt(0),
		adj(n + 1), scc(n + 1), dfs_order(n + 1) {
	}

	void AddEdge(int a, int b) { adj[a].push_back(b); }

	int DFS(int cur) {
		int ret = dfs_order[cur] = ++dfs_cnt; S.push(cur);
		for (const auto& nxt : adj[cur]) {
			if (!dfs_order[nxt]) ret = min(ret, DFS(nxt));
			else if (!scc[nxt]) ret = min(ret, dfs_order[nxt]);
		}
		if (ret == dfs_order[cur]) {
			for (scc_cnt++; S.size();) {
				int t = S.top(); S.pop();
				scc[t] = scc_cnt;
				if (t == cur) break;
			}
		}
		return ret;
	}

	void GetSCC() {
		for (int i = 1; i <= n; i++) if (!dfs_order[i]) DFS(i);
	}
};

void Main(){
	int n,m; cin >> n >> m; 
	SCC G(n); for(int i = 0; i < m; i++){
		int a,b; cin >> a >> b;
		G.AddEdge(a, b);
	}
	G.GetSCC();
	cout << (G.scc_cnt == 1 ? "Yes" : "No") << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}
