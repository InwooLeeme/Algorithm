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

struct P{ int r1; int c1; int r2; int c2; };

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

void Sol(){
    int n; cin >> n;
    vector<P> v(n);
    for(auto& [r1, c1, r2, c2] : v){
        cin >> r1 >> c1 >> r2 >> c2;
    }    
    UnionFind UF(n + 1);
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            bool check = 0;
            if(v[i].r1 > v[j].r2) check = 1;
            if(v[i].r2 < v[j].r1) check = 1;
            if(v[i].c1 > v[j].c2) check = 1;
            if(v[i].c2 < v[j].c1) check = 1;
            if(check) continue;
            UF.Union(i, j);
        }
    }
    int ret = 0;
    for(int i = 0; i < n; i++) if(i == UF.Find(i)) ret++;
    cout << ret << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    int t; cin >> t;
    while(t--) Sol();
    return 0;
}