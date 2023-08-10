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

struct SCC {
	int n, scc_cnt, dfs_cnt;
	vector<vector<int>> adj;
	vector<int> scc, dfs_order;
	stack<int> S;

	SCC(int n = 0) :
		n(n), dfs_order(n + 1),
		adj(n + 1), scc(n + 1),
		scc_cnt(0), dfs_cnt(0) {}

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
		for (int i = 1; i <= n; i++)
			if (!dfs_order[i]) DFS(i);
	}
};

void Main(){
    int n,m; cin >> n >> m;
    SCC G(n); while(m--){
        int a,b; cin >> a >> b;
        G.AddEdge(a + 1, b + 1);
    }
    G.GetSCC();
    vector<int> indegree(G.scc_cnt + 1);
    int ret = 0;
    for(int i = 1; i <= n; i++){
        for(auto nxt : G.adj[i]){
            if(G.scc[i] == G.scc[nxt]) continue;
            indegree[G.scc[nxt]]++;
        }
    }
    for(int i = 1; i <= G.scc_cnt; i++) ret += !indegree[i];
    cout << ret << '\n';
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}