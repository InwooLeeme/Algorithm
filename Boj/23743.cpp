#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#define int int_fast64_t

using tii = tuple<int, int, int>;

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
    fastio;
    int n,m; cin >> n >> m;
    vector<tii> e;
    for(int i = 0; i < m; i++){
        int a,b,c; cin >> a >> b >> c;
        e.push_back({c, a, b});
    }
    for(int i = 1,t; i <= n; i++){
        cin >> t;
        e.push_back({t, 0, i});
    }
    sort(e.begin(), e.end());
    int cost = 0,cnt = 0;
    UnionFind UF(n + 1);
    for(auto& [c, a, b] : e){
        if(UF.Union(a, b)){
            cost += c;
            if(++cnt == n) break;
        }
    }
    cout << cost << "\n";
    return 0;
}