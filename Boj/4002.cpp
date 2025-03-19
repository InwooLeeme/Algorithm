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

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using ti3 = tuple<int, int, int>;
using vp = vector<pii>;

// Build Suffix Array O(NlogN^2)
// result : 0 indexed base, 사전 순으로 i번째가 몇번째 접미사인지?
vector<int> GetSA(const string& s){
    const int n = s.size();
    vector<int> sa(n), r(n + 1), nr(n + 1);
    for(int i = 0; i < n; i++) sa[i] = i, r[i] = s[i];
    for(int d = 1; d < n; d <<= 1){
        auto Cmp = [&](int i, int j){ 
            return r[i] < r[j] || (r[i] == r[j] && r[i + d] < r[j + d]); // shifting 2^d
        };
        sort(sa.begin(), sa.end(), Cmp); // O(NlogN)
        nr[sa[0]] = 1;
        for(int i = 1; i < n; i++){
            nr[sa[i]] = nr[sa[i - 1]] + Cmp(sa[i - 1], sa[i]);
        }
        r = nr;
    }
    return sa;
}

// Get Longest Common Prefix using SA
// isa : sa의 반대, i번째 접미사가 사전 순으로 몇 번째인지?
// isa[sa[i]] = i 성립, isa[sa[i] - 1] : 사전 순으로 바로 앞에 있는 접미사
// Result : LCP 배열(SA배열의 i번째 접미사와 i - 1번째 접미사의 가장 긴 공통 접미사)
vector<int> LCP(vector<int>& sa, const string& s){
    const int n = s.size();
    vector<int> lcp(n), isa(n);
    for(int i = 0; i < n; i++) isa[sa[i]] = i;
    for(int k = 0, i = 0; i < n; i++) if(isa[i]){
        for(int j = sa[isa[i] - 1]; s[i + k] == s[j + k]; k++);
        lcp[isa[i]] = (k ? k-- : 0);
    }
    return lcp;
}

int n,m,mx, par[101010], C[101010],L[101010],I[101010], root = -1;
vi g[101010];
max_pq<int> pq[101010];

int Sol(int cur){
    int res = C[cur];
    for(const auto& nxt : g[cur]){
        res += Sol(nxt);
        auto a = I[cur], b = I[nxt];
        if(SZ(pq[a]) > SZ(pq[b])) swap(a, b);
        while(!pq[a].empty()){
            pq[b].push(pq[a].top()); pq[a].pop();
        }
        while(res > m){
            res -= pq[b].top(); pq[b].pop();
        }
        I[cur] = b;
    }
    mx = max<int>(mx, SZ(pq[I[cur]]) * L[cur]);
    return res;
}

void Main(){
    ri(n, m);
    for(int i = 1; i <= n; i++){
        ri(par[i], C[i], L[i]);
        if(!par[i]) root = i;
        g[par[i]].pb(i);
        pq[i].push(C[i]);
        I[i] = i;
    }
    Sol(root);
    po(mx);
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}
