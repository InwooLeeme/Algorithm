#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t

using pii = pair<int, int>;
using ti3 = tuple<int, int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

constexpr int INF = int(1 << 30);
constexpr int NINF = -int(1 << 30);



void solve(){
	int n,m; cin >> n >> m;
	vector<vector<int>> g(n + 1);
	vector<int> indegree(n + 1);
	for(int i = 0; i < m; i++){
		int a,b; cin >> a >> b;
		g[a].push_back(b); indegree[b]++;
	}
	queue<int> q;
	for(int i = 1; i <= n; i++){
		if(indegree[i]) continue;
		q.push(i);
	}	
	bool flag = 0;
	while(q.size()){
		if(q.size() >= 2) flag = 1;
		auto cur = q.front(); q.pop();
		for(const auto& nxt : g[cur]){
			if(--indegree[nxt] == 0) q.push(nxt);
		}
		cout << cur << "\n";
	}
	cout << flag << "\n";
}

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	int t = 1;
	//cin >> t;
	for(int tc = 1; tc <= t; tc++) solve();
}
