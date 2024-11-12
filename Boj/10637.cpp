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
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define fi first
#define se second
#define pb push_back
#define SZ(x) (int)x.size()
template<typename T>
void printv(vector<T> v) {for (auto e : v) { cout << e << " "; }  cout << "\n";} 
template<typename T>
void printvv(vector<T> vv) {for (int i=0; i<vv.size(); i++) {cout << i << ": "; for (auto e : vv[i]) {cout << e << " ";}cout << "\n";}}
template<typename T>
void ri(T &x) {cin >> x;}
template<typename T, typename... Args>
void ri(T &x, Args&... args) { ri(x);ri(args...) ;}
template<typename T>
void ri(vector<T> &v) {for (auto &x : v) {cin >> x;}}
template<typename T, typename... Args>
void ri(vector<T> &v, Args&... args) {ri(v);ri(args...);}
template<typename T>
void po(T x) {cout << x << "\n";}
template<typename T, typename... Args>
void po(T x, Args... args) {cout << x << " ";po(args...) ;}
template<typename T>
void po(vector<T> &a) {
for (int i=0; i<(int)a.size(); i++) {
if (i <(int)a.size()-1) {
cout << a[i] << " ";}
else cout << a[i] << "\n";
}
}

void __print(int x) {cerr << x;}
void __print(signed x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T1, typename T2, typename T3>
void __print(const tuple<T1, T2, T3> &x) {cerr << '{'; __print(get<0>(x)); cerr << ','; __print(get<1>(x)); cerr << ','; __print(get<2>(x)); cerr << '}';}
template<typename T1, typename T2, typename T3, typename T4>
void __print(const tuple<T1, T2, T3, T4> &x) {cerr << '{'; __print(get<0>(x)); cerr << ','; __print(get<1>(x)); cerr << ','; __print(get<2>(x)); cerr << ','; __print(get<3>(x)); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
template<typename T1, typename T2>
void __print(map<T1,T2> &mp) {for (auto [k,v] : mp) {cerr << '{'; __print(k); cerr << ':'; __print(v); cerr << '}';}}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_pq = priority_queue<T>;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R>
using ordered_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R>
using ordered_multimap = tree<T, R, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int PRECISION = 0;
constexpr int INF = int(2e18);
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int n,m;

struct UnionFind{
    vector<int> P;
    UnionFind(int n):P(n + 1){
        iota(all(P), 0);
    }
    int Find(int x){ return x == P[x] ? x : P[x] = Find(P[x]); }
    bool Union(int a, int b){
        a = Find(a), b = Find(b);
        if(a == b) return 0;
        P[b] = a; return 1;
    }
};

template<size_t sz>
struct SegTree {
	vector<int> tree, lazy;
	SegTree() : tree(sz << 1, INF), lazy(sz << 1, INF) {}
	void Push(int node, int L, int R) {
		if (node < sz) for (const int nxt : { node << 1, node << 1 | 1}) lazy[nxt] = min<int>(lazy[nxt], lazy[node]);
		tree[node] = min<int>(tree[node], lazy[node]), lazy[node] = INF;
	}
	void Update(int l, int r, int val, int node = 1, int L = 1, int R = sz) {
		Push(node, L, R);
		if (r < L || R < l) return;
		if (l <= L && R <= r) { lazy[node] = val, Push(node, L, R); return; }
		int mid = L + R >> 1;
		Update(l, r, val, node << 1, L, mid);
		Update(l, r, val, node << 1 | 1, mid + 1, R);
		tree[node] = min<int>(tree[node << 1], tree[node << 1 | 1]);
	}
	int Query(int l, int r, int node = 1, int L = 1, int R = sz) {
		Push(node, L, R);
		if (r < L || R < l) return INF;
		if (l <= L && R <= r) return tree[node];
		int mid = L + R >> 1;
		return min<int>(Query(l, r, node << 1, L, mid), Query(l, r, node << 1 | 1, mid + 1, R));
	}
};

SegTree<1 << 17> ST;
const int sz = 1 << 17;
int Top[sz], Par[sz], Dep[sz], Sz[sz], In[sz], Out[sz], Cost[sz], temp;
vector<int> G[sz], Inp[sz];

void Connect(int a, int b){
    Inp[a].pb(b); Inp[b].pb(a);
}

void DFS(int cur = 1, int prev = -1){
    for(auto& nxt : Inp[cur]){
        if(nxt == prev) continue;
        G[cur].pb(nxt); 
        DFS(nxt, cur);
    }
}

void DFS1(int cur = 1){
    Sz[cur] = 1;
    for(auto& nxt : G[cur]){
        Dep[nxt] = Dep[cur] + 1; Par[nxt] = cur;
        DFS1(nxt); Sz[cur] += Sz[nxt];
        if(Sz[nxt] > Sz[G[cur][0]]) swap(nxt, G[cur][0]);
    }
}

void DFS2(int cur = 1){
    In[cur] = ++temp;
    for(const auto& nxt : G[cur]){
        Top[nxt] = (nxt == G[cur][0] ? Top[cur] : nxt);
        DFS2(nxt);
    }
    Out[cur] = temp;
}

void Init(){
    DFS(); DFS1(); DFS2(Top[1] = 1);
}

void Update(int a, int b, int c){
    for(; Top[a] != Top[b]; a = Par[Top[a]]){
        if(Dep[Top[a]] < Dep[Top[b]]) swap(a, b);
        ST.Update(In[Top[a]], In[a], c);
    }
    if(In[a] > In[b]) swap(a, b);
    ST.Update(In[a] + 1, In[b], c);
}

int Query(int a, int b){
    int ret = INF;
    for(; Top[a] != Top[b]; a = Par[Top[a]]){
        if(Dep[Top[a]] < Dep[Top[b]]) swap(a, b);
        ret = min<int>(ret, ST.Query(In[Top[a]], In[a]));
    }
    if(In[a] > In[b]) swap(a, b);
    ret = min<int>(ret, ST.Query(In[a] + 1, In[b]));
    return ret;
}

void Main(){
    ri(n, m);
    vector<array<int, 5>> E;
    vector<int> ret(m, -1);
    for(int i = 0; i < m; i++){
        int a,b,c; ri(a, b, c);
        E.pb({c, a, b, 0, i});
    }
    sort(all(E));
    UnionFind UF(n + 1);
    int mst = 0,cnt = 0;
    for(int i = 0; i < m; i++){
        auto c = E[i][0], a = E[i][1], b = E[i][2], k = E[i][3], idx = E[i][4];
        if(UF.Union(a, b)){
            mst += c;
            E[i][3] = 1;
            Connect(a, b);
            if(++cnt == n - 1) break;
        }
    }
    Init();
    for(int i = 0; i < m; i++){
        auto c = E[i][0], a = E[i][1], b = E[i][2], k = E[i][3], idx = E[i][4];
        if(!k) Update(a, b, c);
    }
    sort(all(E), [&](array<int, 5>& a, array<int, 5>& b){
        return a[4] < b[4];
    });
    for(int i = 0; i < m; i++){
        auto c = E[i][0], a = E[i][1], b = E[i][2], k = E[i][3], idx = E[i][4];
        if(!k) ret[idx] = mst;
        else{
            auto t = Query(a, b);
            if(t == INF) ret[idx] = -1;
            else ret[idx] = mst + t - c;
        }
    }
    for(const auto& i : ret) po(i);
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}
