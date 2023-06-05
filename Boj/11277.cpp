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
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

vector<int> adj[20002], rev[20002];

bitset<20002> visited;
vector<int> order;
int SCC[20002];

void dfs(int cur) {
	visited[cur] = 1;
	for (auto nxt : adj[cur]) {
		if (visited[nxt]) continue;
		dfs(nxt);
	}
	order.push_back(cur);
}

void dfs_rev(int cur, int num) {
	visited[cur] = 1;
	SCC[cur] = num;
	for (auto nxt : rev[cur]) {
		if (visited[nxt]) continue;
		dfs_rev(nxt, num);
	}
}

int ORI(int a) {
	return a > 0 ? a * 2 : -a * 2 + 1;
}

int NOT(int a) {
	return a > 0 ? a * 2 + 1 : -a * 2;
}

int32_t main() {
	fastio;
	int n, m; cin >> n >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		adj[NOT(a)].push_back(ORI(b));
		adj[NOT(b)].push_back(ORI(a));
		rev[ORI(a)].push_back(NOT(b));
		rev[ORI(b)].push_back(NOT(a));
	}
	for (int i = 1 * 2; i <= n * 2 + 1; i++) {
		if (!visited[i]) dfs(i);
	}
	visited.reset();
	reverse(order.begin(), order.end());
	int cnt = 0;
	for (auto i : order) {
		if (!visited[i]) dfs_rev(i, ++cnt);
	}
	for (int i = 1; i <= n; i++) {
		if (SCC[ORI(i)] == SCC[NOT(i)]) {
			cout << 0 << '\n';
			return 0;
		}
	}
	cout << 1 << '\n';
}