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

using pt = pair<int, int>;
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
    int n;
    while(cin >> n and n){
        vector<pt> v(n);
        for(auto& [a, b] : v) cin >> a >> b;
        UnionFind UF(n + 1);
        vector<tii> e;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                auto d = sqrt((v[i].first - v[j].first) * (v[i].first - v[j].first) + (v[i].second - v[j].second) * (v[i].second - v[j].second));
                e.push_back({d, i, j});
            }
        }
        sort(e.begin(), e.end());
        double cost = 0.0;
        int cnt = 0;
        for(auto& [c, a, b] : e){
            if(UF.Union(a, b)){
                cost += c;
                if(++cnt == n - 1) break;
            }
        }
        cout << fixed << setprecision(2) << cost << "\n";
    }
    return 0;
}