#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int int_fast64_t
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

using pii = pair<int, int>;

struct SegTree {
	int tree[1 << 21]; //arr[0, n-1] -> tree[sz, sz + n - 1]
	int sz = 1 << 20;

	void Construct() {
		for (int i = sz - 1; i > 0; i--) {
			tree[i] = tree[i << 1] + tree[i << 1 | 1];
		}
	}
	//i : 1-indexed
	void Update(int i, int val) {
		--i |= sz; tree[i] = val;
		while (i >>= 1) {
			tree[i] = tree[i << 1] + tree[i << 1 | 1];
		}
	}
	//[l, r] : 1-indexed
	int query(int L, int R, int nodeNum, int nodeL, int nodeR) {
		if (R < nodeL || nodeR < L) return 0;
		if (L <= nodeL && nodeR <= R) return tree[nodeNum];
		int mid = nodeL + nodeR >> 1;
		return query(L, R, nodeNum * 2, nodeL, mid) + query(L, R, nodeNum * 2 + 1, mid + 1, nodeR);
	}
	int Query(int l, int r) {
		return query(l, r, 1, 1, sz);
	}
} ST;

struct Query1{
    int x,y;
};

struct Query2{
    int k,x,y;
    bool operator < (const Query2& Q){
        return k < Q.k;
    }
};

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n,q; cin >> n;
    for(int i = 0; i < n; i++) cin >> ST.tree[ST.sz + i];
    ST.Construct();
    cin >> q;
    vector<Query1> updates;
    vector<pair<Query2,int>> Quies;
    int query2_cnt = 0;
    while(q--){
        int t,a,b,k; cin >> t;
        if(t == 1){
            cin >> a >> b;
            updates.push_back({a, b});
        }
        else{
            cin >> k >> a >> b;
            Quies.push_back({{k, a, b}, query2_cnt++});
        }
    }
    sort(Quies.begin(), Quies.end(), [&](pair<Query2,int>& a, pair<Query2,int>& b){
        return a.first < b.first;
    });
    int cnt = 0,ret[101010] = {};
    for(const auto& i : Quies){
        auto k = i.first.k,x = i.first.x, y = i.first.y;
        while(cnt < k){
            cnt++;
            auto i = updates[cnt - 1].x,val = updates[cnt - 1].y;
            ST.Update(i, val);
        }
        auto res = ST.Query(x, y);
        ret[i.second] = res;
    }
    for(int i = 0; i < query2_cnt; i++) cout << ret[i] << "\n";
}