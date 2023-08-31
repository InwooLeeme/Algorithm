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

vector<int> par(111111),cnt(111111, 1);
int v[111'111],water[111'111];

int Find(int x){ return x == par[x] ? x : par[x] = Find(par[x]); }
bool Union(int a, int b){
    a = Find(a), b = Find(b);
    if(a == b) return 0;
    par[b] = a;
    water[a] += water[b];
    cnt[a] += cnt[b];
    return 1;
}

void Main(){
    int n,m,q; cin >> n >> m >> q;
    iota(par.begin(), par.end(), 0);
    for(int i = 1; i <= n; i++){
        int t; cin >> t;
        water[i] = (t == 1 ? 1 : -1);
    }
    while(m--){
        int a,b; cin >> a >> b;
        Union(a, b);
    }
    while(q--){
        int x; cin >> x;
        cout << (water[Find(x)] > 0 ? 1 : 0) << "\n";
    }
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}