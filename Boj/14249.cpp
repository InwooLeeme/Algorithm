#include <bits/stdc++.h>
using namespace std;

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

	vector<int> GetIndegree(){
		vector<int> ret(scc_cnt + 1);
		for(int i = 1; i <= n; i++){
			for(auto& nxt : adj[i]){
				if(scc[i] == scc[nxt]) continue;
				ret[scc[nxt]]++;
			}
		}
		return ret;
	}

	vector<vector<int>> GetDAG(){
		vector<vector<int>> G(scc_cnt + 1);
		for(int i = 1; i <= n; i++){
			for(auto& nxt : adj[i]){
				if(scc[i] == scc[nxt]) continue;
				G[scc[i]].push_back(scc[nxt]);
			}
		}
		for(auto& i : G){
			sort(i.begin(), i.end());
			i.erase(unique(i.begin(), i.end()), i.end());
		}
		return G;
	}
};
 
int main(){
	ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
	int n; cin >> n;
	SCC scc(n);
	vector<int> v(n + 1);
	auto Bound = [&](int x) -> bool{ return x <= 0 or x > n; };
	for(int i = 1; i <= n; i++){
		cin >> v[i];
		auto prv = i - v[i];
		auto nxt = i + v[i];
		if(!Bound(prv)){
			scc.AddEdge(i, prv);
		}
		if(!Bound(nxt)){
			scc.AddEdge(i, nxt);
		}
	}
	int x; cin >> x;
	scc.GetSCC(); int st = scc.scc[x];
	vector<int> D(scc.scc_cnt + 1, 0);
	vector<vector<int>> G(scc.scc_cnt + 1);
	for(int i = 1; i <= n; i++){
		G[scc.scc[i]].push_back(i);
	}
	for(int i = 1; i <= scc.scc_cnt; i++){
		for(const auto& a : G[i]) for(const auto& b : scc.adj[a]) D[i] = max<int>(D[i], D[scc.scc[b]]);
		D[i] += G[i].size();
	}
	cout << D[st] << "\n";
	return 0;
}
