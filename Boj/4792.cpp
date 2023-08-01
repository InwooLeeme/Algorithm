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

struct Edge{ char T; int a,b; };

const int PRECISION = 0;

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

bool RedMST(Edge& a, Edge& b){ return a.T > b.T; }
bool BlueMST(Edge& a, Edge& b){ return a.T < b.T; }

int MST(vector<Edge>& e, bool flag = 0){
    UnionFind UF(n + 1);
    int cost = 0,cnt = 0;
    sort(e.begin(), e.end(), !flag ? RedMST : BlueMST);
    for(auto& [c, a, b] : e){
        if(UF.Union(a, b)){
            cost += (c == 'B');
            if(++cnt == n - 1) break;
        }
    }
    return cost;
}

void Sol(){
    vector<Edge> e(m);
    for(auto& [c, a, b] : e) cin >> c >> a >> b;
    auto BlueMin = MST(e, 0); auto BlueMax = MST(e, 1);
    cout << (BlueMin <= k and k <= BlueMax) << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    while(cin >> n >> m >> k and n) Sol();
    return 0;
}