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

struct UnionFind {
	vector<int> P;
	UnionFind(int n) : P(n, -1) {}
	int Find(int x) { return P[x] < 0 ? x : P[x] = Find(P[x]); }
	bool Union(int a, int b) {
		a = Find(a), b = Find(b);
		if (a == b) return 0;
		P[a] += P[b]; P[b] = a; return 1;
	}
	int Cnt(int x) { return -P[Find(x)]; }
};

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n,m,ret = int(2e9); cin >> n >> m;
    vector<p> v(n); for(auto& [x, y] : v) cin >> x >> y;
    vector<vector<p>> w(n, vector<p>());
    UnionFind UF(n + 1);
    while(m--){ int a,b; cin >> a >> b; --a,--b;UF.Union(a, b);}
    for(int i = 0; i < n; i++) w[UF.Find(i)].push_back(v[i]);
    for(int i = 0; i < n; i++) if(w[i].size()){
        int mxx = 0,mxy = 0;
        int mnx = int(2e9), mny = int(2e9);
        for(const auto& [x, y] : w[i]){
            mxx = max<int>(mxx, x); mxy = max<int>(mxy, y);
            mnx = min<int>(mnx, x); mny = min<int>(mny, y);
        }
        ret = min<int>(ret, mxx - mnx + mxy - mny << 1);
    }
    cout << ret << '\n';
    return 0;
}