#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int int_fast64_t
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

using tii = tuple<int, int, int>;

vector<vector<int>> ret;

struct UnionFind { // union-by-rank ver.
	vector<int> par, rank, cnt;
	UnionFind(int n) : par(n), rank(n, 1), cnt(n, 1) {
		iota(par.begin(), par.end(), 0);
	}
	int Find(int x) {
		return x == par[x] ? x : par[x] = Find(par[x]);
	}
	bool Union(int a, int b) {
		a = Find(a), b = Find(b);
		if (a == b) return 0;
		if (rank[a] < rank[b]) swap(a, b);
		par[b] = a;
		rank[a] += rank[a] == rank[b];
		cnt[a] += cnt[b];
		return 1;
	}
};

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
	ret.resize(n + 1);
	vector<tii> e;
	UnionFind UF(n + 1);
	for(int i = 1; i < n; i++){
		for(int j = i + 1,t; j <= n; j++){
			cin >> t;
			e.push_back({t, i, j});
			e.push_back({t, j, i});
		}
	}
	sort(e.begin(), e.end());
	int cost = 0,cnt = 0;
	for(auto& i : e){
		auto c = get<0>(i),a = get<1>(i),b = get<2>(i);
		if(UF.Find(a) != UF.Find(b)){
			ret[a].push_back(b);
			ret[b].push_back(a);
			cost += c;
			UF.Union(a, b);
			if(++cnt == n - 1) break;
		}
	}
	for(int i = 1; i <= n; i++){
		sort(ret[i].begin(), ret[i].end());
		cout << ret[i].size() << ' ';
		for(auto& j : ret[i]) cout << j << ' ';
		cout << "\n";
	}
}   