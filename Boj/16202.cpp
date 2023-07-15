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

using tii = tuple<int, int, int>;

int n,m,k;

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
    cin >> n >> m >> k;
    vector<tii> e;
    for(int c = 1; c <= m; c++){
        int a,b; cin >> a >> b;
        e.push_back({c, a, b});
    }
    sort(e.begin(), e.end());
    vector<int> ret(k);
    bool check = 0;
    for(int i = 0; i < k; i++){
        UnionFind UF(n + 2);
        int cnt = 0,cost = 0;
        for(int j = 0; j < e.size(); j++){
            if(i != 0 and j <= i - 1) continue;
            auto& [c, a, b] = e[j];
            if(UF.Union(a, b)){
                cost += c;
                if(++cnt == n - 1) break;
            }
        }
        check = (cnt == n - 1 ? 0 : 1); 
        ret[i] = (!check ? cost : 0);
    }
    for(auto& i : ret) cout << i << " ";
    return 0;
}