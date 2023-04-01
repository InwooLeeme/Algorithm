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


struct SegTree{
    struct Node{
        int sum, l, r, mx;
    };
    Node f(Node a, Node b){
        if(a.sum == INF) return b;
        if(b.sum == INF) return a;
        Node ret;
        ret.sum = a.sum + b.sum;
        ret.l = max<int>(a.l, a.sum + b.l);
        ret.r = max<int>(b.r, b.sum + a.r);
        ret.mx = max<int>({a.mx, b.mx, a.r + b.l});
        return ret;
    }
    const int INF = int(1e18);
    Node tree[1 << 18];
    int sz = 1 << 17;

    SegTree(){
        for(int i = sz; i < sz * 2; i++) tree[i] = {INF, INF, INF, INF};
    }

    void Update(int i, int val){
        --i |= sz; tree[i] = {val, val, val, val};
        while(i >>= 1) tree[i] = f(tree[i << 1], tree[i << 1 | 1]);
    }

    Node Query(int L, int R, int nodeNum, int nodeL, int nodeR){
        if(R < nodeL || nodeR < L) return {INF, INF, INF, INF};
        if(L <= nodeL and nodeR <= R) return tree[nodeNum];
        int mid = nodeL + nodeR >> 1;
        return f(Query(L, R, nodeNum << 1, nodeL, mid), Query(L, R, nodeNum << 1 | 1, mid + 1, nodeR));
    }
} ST;

int32_t main(){
    fastio;
    int n,q,u,v; cin >> n >> q >> u >> v;
    for(int i = 1; i <= n; i++){
        int t; cin >> t;
        ST.Update(i, u*t + v);
    }
    while(q--){
        int t,a,b; cin >> t >> a >> b;
        if(t == 0) cout << ST.Query(a, b, 1, 1, ST.sz).mx - v << "\n";
        else ST.Update(a, u * b + v);
    }
    return 0;
}