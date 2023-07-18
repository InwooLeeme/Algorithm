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
    int n,m; cin >> n >> m;
    vector<tii> e(m);
    for(auto& [c, a, b] : e) cin >> a >> b >> c;
    UnionFind UF(n + 1);
    sort(e.begin(), e.end());
    int mx = 0,cnt = 0;
    vector<int> ret,s;
    for(auto& [c, a, b] : e){
        if(UF.Union(a, b)){
            ret.push_back(c);
            if(++cnt == n - 1) break;
        }
    }
    s.resize(ret.size());
    iota(s.begin(), s.end(), 1);
    bool flag = 0;
    for(int i = 0; i < ret.size(); i++){
        if(ret[i] != s[i]){
            cout << s[i] << "\n";
            return 0;
        }
    }
    cout << *max_element(ret.begin(), ret.end()) + 1 << "\n";
    return 0;
}