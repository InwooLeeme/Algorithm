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

struct Node{
    int v,lazy;
    Node *l, *r;
    Node():l(nullptr),r(nullptr),v(0),lazy(0){}
    void Push(int s,int e){
        if(!lazy) return;
        v += lazy * (e - s + 1);
        if(s == e){ lazy = 0; return; }
        int mid = s + e >> 1;
        if(!l) l = new Node();
        if(!r) r = new Node();
        l->lazy += lazy; r->lazy += lazy;
        lazy = 0;
    }
};

void Update(Node* nd, int l, int r, int k, int s = 1, int e = 1e9){
    nd->Push(s, e);
    if(r < s || e < l) return;
    if(l <= s and e <= r){
        nd->lazy += k; nd->Push(s, e);
        return;
    }
    int mid = s + e >> 1;
    if(!nd->l) nd->l = new Node();
    if(!nd->r) nd->r = new Node();
    Update(nd->l, l, r, k, s, mid);
    Update(nd->r, l, r, k, mid + 1, e);
    nd->v = nd->l-> v + nd->r->v;
}

int Query(Node* nd, int l, int r, int s = 1, int e = 1e9){
    if(!nd) return 0;
    nd->Push(s, e);
    if(r < s || e < l) return 0;
    if(l <= s and e <= r) return nd->v;
    int mid = s + e >> 1;
    return Query(nd->l, l, r, s, mid) + Query(nd->r, l, r, mid + 1, e);
}

struct query{
    int T, idx, s, e, k, id;
    bool operator<(const query& q) const{
        return idx == q.idx ? T < q.T : idx < q.idx;
    };
};

int ret[50101];
int check[50101];

void Main(){
    int Q; cin >> Q;
    int cnt = 0,res = 0;
    Node* root = new Node();
    vector<query> v;
    for(int i = 1; i <= Q; i++){
        int t,a,b,k; cin >> t >> a >> b >> k;
        if(t == 1) v.push_back({t, ++cnt, a, b, k, 0});
        else if(t == 2) v.push_back({t, k, a, b, k, ++res}), check[i] = 1;
    }
    sort(v.begin(), v.end());
    for(auto& [T, idx, s, e, k, id] : v){
        if(T == 1) Update(root, s, e, k);
        else if(T == 2) ret[id] = Query(root, s, e);
    }
    for(int i = 1; i <= res; i++) cout << ret[i] << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}