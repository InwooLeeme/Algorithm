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

struct SegTree {
	int tree[1 << 19]; //arr[0, n-1] -> tree[sz, sz + n - 1]
	int sz = 1 << 18;

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
	int Query(int l, int r) {
		--l |= sz, --r |= sz;
		int ret = 0;
		while (l <= r) {
			if (l & 1) ret += tree[l++];
			if (~r & 1) ret += tree[r--];
			l >>= 1, r >>= 1;
		}
		return ret;
	}
};

struct HLD{
    int n,q;
    int sz[200011], dep[200011], par[200011];
    int top[200011], in[200011], out[200011];
    vector<int> inp[200011], G[200011];

    bool vist[200011];
    void DFS(int cur = 1){
        vist[cur] = 1;
        for(auto& nxt : inp[cur]){
            if(vist[nxt]) continue;
            vist[nxt] = 1;
            G[cur].push_back(nxt);
            DFS(nxt); 
        }
    }

    void DFS1(int cur = 1){
        sz[cur] = 1;
        for(auto& nxt : G[cur]){
            dep[nxt] = dep[cur] + 1; par[nxt] = cur;
            DFS1(nxt); sz[cur] += sz[nxt];
            if(sz[nxt] > sz[G[cur][0]]) swap(nxt, G[cur][0]);
        }
    }
    // For ETT
    int temp = 0;
    void DFS2(int cur = 1){
        in[cur] = ++temp;
        for(auto& nxt : G[cur]){
            top[nxt] = (nxt == G[cur][0] ? top[cur] : nxt);
            DFS2(nxt);
        }
        out[cur] = temp;
    }

    SegTree ST;
    void Precalc(){
        cin >> n >> q;
        for(int i = 1; i <= n - 1; i++){
            int t; cin >> t;
            inp[i + 1].push_back(t);
            inp[t].push_back(i + 1);
        }
        top[1] = 1;
        DFS(); DFS1(); DFS2();
        for(int i = 1; i <= n; i++){
            ST.tree[ST.sz - 1 + in[i]] = 1;
        }
        ST.Construct();
    }

    int LCA(int a, int b){
        while(top[a] != top[b]){
            if(dep[top[a]] < dep[top[b]]) swap(a, b);
            a = par[top[a]];
        }
        return dep[a] < dep[b] ? a : b;
    }

    void Update(int idx, int val){
        ST.Update(in[idx], val);
    }

    int Query(int a, int b){
        int ret = 0;
        while(top[a] != top[b]){
            if(dep[top[a]] < dep[top[b]]) swap(a, b);
            int st = top[a];
            ret += ST.Query(in[st], in[a]);
            a = par[st];
        }
        if(a == b) return ret;
        if(dep[a] > dep[b]) swap(a, b);
        ret += ST.Query(in[a], in[b]);
        ret -= ST.tree[ST.sz - 1 + in[LCA(a, b)]];
        return ret;
    }

    bool Sol(int a, int b){
        return Query(a, b) == dep[a] + dep[b] - 2*dep[LCA(a, b)];
    }
} hld;

void Main(){
    hld.Precalc();
    while(hld.q--){
        int a,b,c; cin >> a >> b >> c;
        bool check = hld.Sol(a, b);
        cout << (check ? "YES" : "NO") << "\n";
        if(c and check) hld.Update(a, 0);
        if(c and !check) hld.Update(b, 0);
    }
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}