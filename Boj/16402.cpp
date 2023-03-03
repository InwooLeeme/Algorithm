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
#define all(v) v.begin(), v.end()
#define IDX(x) lower_bound(all(I), x) - I.begin()

struct UnionFind {
	vector<int> par;
	UnionFind(int n) : par(n) {
		iota(par.begin(), par.end(), 0);
	}
	int Find(int x) {
		return x == par[x] ? x : par[x] = Find(par[x]);
	}
	void Union(int a, int b) {
		a = Find(a), b = Find(b);
		par[b] = a;
	}
	void MovePar(int a, int b) {
		par[b] = a; par[a] = a;
	}
};
int32_t main(){
    fastio;
    int n,m; cin >> n >> m; 
    vector<string> I(n);
    for(int i = 0; i < n; i++) cin >> I[i] >> I[i] >> I[i];
    sort(all(I));
    cin.ignore();
    UnionFind UF(n);
    while(m--){
        string s,_a,_b; getline(cin, s);
        int t;
        for(auto& i : s) if(i == ',') i = ' ';
        stringstream in(s);
        in >> _a >> _a >> _a >> _b >> _b >> _b >> t;
        int a = IDX(_a),b = IDX(_b);
        if (UF.Find(a) == UF.Find(b)) {
			if (t == 1) UF.MovePar(a, b);
			else UF.MovePar(b, a);
		}
		else {
			if (t == 1) UF.Union(a, b);
			else UF.Union(b, a);
		}
    }   
    int ret = 0;
    for(int i = 0; i < n; i++) if(i == UF.Find(i)) ret++;
    cout << ret << "\n";
    for(int i = 0; i < n; i++) if(i == UF.Find(i)) cout << "Kingdom of " << I[i] << "\n";
    return 0;
}