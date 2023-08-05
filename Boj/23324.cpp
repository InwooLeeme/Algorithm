#pragma GCC target("avx,avx2,fma")
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


void Main(){
	int n,m,k; cin >> n >> m >> k;
	UnionFind UF(n + 1);
	int x,y; for(int i = 1; i <= m; i++){
		int a,b; cin >> a >> b;
		if(i == k){
			x = a,y = b;
			continue;
		}
		UF.Union(a, b);
	}
	if(UF.Find(x) == UF.Find(y)){
		cout << 0 << "\n";
		return;
	}
	cout << UF.cnt[UF.Find(x)] * UF.cnt[UF.Find(y)] << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();	
    return 0;
}
