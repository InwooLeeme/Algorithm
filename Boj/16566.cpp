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

template<size_t sz>
struct FenwickTree {
	vector<int> tree;
	FenwickTree() : tree(sz + 1) {}
	void update(int i, int val) {
		for (; i <= sz; i += i & -i) tree[i] += val;
	}
	int query(int i) {
		int ret = 0;
		for (; i; i -= i & -i) ret += tree[i];
		return ret;
	}
};

int32_t main(){
    fastio;
    FenwickTree<1 << 22> FT;
    int n,m,k; cin >> n >> m >> k;
    for(int i = 1,t; i <= m; i++){
        cin >> t;
        FT.update(t, 1);
    }
    while(k--){
        int t; cin >> t;
        int lo = t,hi = n; // [t, n] 구간에 수가 존재하는가?
        while(lo + 1 < hi){
            int mid = lo + hi >> 1;
            if(FT.query(mid) - FT.query(t) == 0) lo = mid;
            else hi = mid;
        }
        cout << hi << "\n";
        FT.update(hi, -1);
    }
    return 0;
}