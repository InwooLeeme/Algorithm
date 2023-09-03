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

const int INF = int(1e18);

template<typename T = int64_t, size_t sz = 20, typename F = plus<T>>
struct SegTree {
	vector<T> tree; T t; F f{};
	SegTree(T t = T()) : tree(1 << sz + 1, t), t(t) {}
	explicit SegTree(T t, const F& f) : tree(1 << sz + 1, t), t(t), f(f) {}

	void Update(int i, T val) {
		--i |= 1 << sz; tree[i] = val;
		while (i >>= 1) tree[i] = f(tree[i << 1], tree[i << 1 | 1]);
	}
	T Query(int l, int r) {
		T L = t, R = t; --l |= 1 << sz, --r |= 1 << sz;
		while (l <= r) {
			if (l & 1) L = f(L, tree[l++]);
			if (~r & 1) R = f(tree[r--], R);
			l >>= 1, r >>= 1;
		}
		return f(L, R);
	}
};

void Main(){
    int t; cin >> t; while(t--){
        int n,m; cin >> n >> m;
        auto Max = [](int& a, int& b) -> int{ return a < b ? b : a; };
        auto Min = [](int& a, int& b) -> int{ return a < b ? a : b; };
        using MinSegTree = SegTree<int, 17, decltype(Min)>;
        using MaxSegTree = SegTree<int, 17, decltype(Max)>;
        MinSegTree Min_ST(INF, Min); MaxSegTree Max_ST(-INF, Max);
        vector<int> v(n + 1); iota(v.begin(), v.end(), 0);
        for(int i = 1; i <= n; i++){
            Min_ST.Update(i, i);
            Max_ST.Update(i, i);
        }
        while(m--){
            int t,a,b; cin >> t >> a >> b; ++a,++b;
            if(!t){
                swap(v[a], v[b]);
                Min_ST.Update(a, v[a]); Min_ST.Update(b, v[b]);
                Max_ST.Update(a, v[a]); Max_ST.Update(b, v[b]);
            }
            else{
                auto mx = Max_ST.Query(a, b); auto mn = Min_ST.Query(a, b);
                if(mx == b and mn == a) cout << "YES" << "\n";
                else cout << "NO" << "\n";
            }
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}