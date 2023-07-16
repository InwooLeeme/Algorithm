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

using p = pair<int, int>;
using tii = tuple<double, int, int>;

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
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n,q; cin >> n;
    UnionFind UF(n + 1);
    vector<p> v(n),ret;
    for(auto& [x, y] : v) cin >> x >> y;
    cin >> q;
    while(q--){
        int a,b; cin >> a >> b; --a,--b;
        UF.Union(a, b);
    }
    vector<tii> e;
    for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++){
        e.push_back({sqrt((v[i].first - v[j].first) * (v[i].first - v[j].first) + (v[i].second - v[j].second) * (v[i].second - v[j].second)), i, j});
        e.push_back({sqrt((v[i].first - v[j].first) * (v[i].first - v[j].first) + (v[i].second - v[j].second) * (v[i].second - v[j].second)), j, i});
    }
    sort(e.begin(), e.end());
    double cost = 0.0;
    int cnt = 0;
    for(auto& [c, a, b] : e){
        if(UF.Union(a, b)){
            cost += c;
            ret.push_back({a, b});
            if(++cnt == n - 1) break;
        }
    }
    cout << fixed << setprecision(2) << cost << '\n';
    for(auto& [a, b] : ret) cout << a + 1 << ' ' << b + 1 << '\n';
    return 0;
}