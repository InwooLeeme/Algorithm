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
bitset<202020> vist;
int mx[202020][20], mn[202020][20], dep[202020], D[202020][20];
vector<pair<int, int>> G[202020];

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

void DFS(int cur, int d){
    vist[cur] = 1;
    dep[cur] = d;
    for(const auto& [cost, nxt] : G[cur]){
        if(vist[nxt]) continue;
        D[nxt][0] = cur;
        mx[nxt][0] = mn[nxt][0] = cost;
        DFS(nxt, d + 1);
    }
}

void PreCal(){
    for(int j = 1; j < 20; j++) for(int i = 1; i <= n; i++){
        D[i][j] = D[D[i][j - 1]][j - 1];
        mn[i][j] = min<int>(mn[i][j - 1], mn[D[i][j - 1]][j - 1]);
		mx[i][j] = max<int>(mx[i][j - 1], mx[D[i][j - 1]][j - 1]);
    }
}

pair<int, int> LCA(int a, int b){
    if(dep[a] < dep[b]) swap(a, b);
    int diff = dep[a] - dep[b];
    int lo = INF, hi = -INF;
    for(int i = 0; diff; i++){
        if(diff & 1){
            lo = min<int>(lo, mn[a][i]);
            hi = max<int>(hi, mx[a][i]);
            a = D[a][i];
        }
        diff >>= 1;
    }
    if(a == b) return {lo, hi};
    for(int i = 19; i >= 0; i--) if(D[a][i] != D[b][i]){
        lo = min<int>({lo, mn[a][i], mn[b][i]});
        hi = max<int>({hi, mx[a][i], mx[b][i]});
        a = D[a][i];
        b = D[b][i];
    }
    lo = min<int>({lo, mn[a][0], mn[b][0]});
    hi = max<int>({hi, mx[a][0], mx[b][0]});
    return {lo, hi};
}

void Main(){
    ri(n, m);
    UnionFind UF(n + 1);
    vector<array<int, 4>> E;
    for(int i = 0; i < m; i++){
        int a,b,c; ri(a, b, c);
        E.pb({c, a, b, i});
    }
    sort(all(E));
    int cnt = 0,cost = 0;
    vector<int> ret(m, -1),have;
    for(const auto& [c, a, b, idx] : E){
        if(UF.Union(a, b)){
            cost += c;
            have.pb(idx);
            G[a].pb({c, b}); G[b].pb({c, a});
            if(++cnt == n - 1) break;
        }
    }
    for(const auto& i : have) ret[i] = cost;
    DFS(1, 0);
    PreCal();
    sort(all(E), [&](array<int, 4>& a, array<int, 4>& b){
        return a[3] < b[3];
    });
    for(int i = 0; i < m; i++){
        if(ret[i] != -1) continue;
        int c = E[i][0], a = E[i][1], b = E[i][2], idx = E[i][3];
        auto [lo, hi] = LCA(a, b);
        ret[i] = cost + c - hi;
    }
    for(const auto& i : ret) po(i);
}   

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}
