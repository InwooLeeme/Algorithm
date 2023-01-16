//////////////////////////////////////////////////////////////////////////////
/* 
 _____                            ______                             _        
/  ___|                           | ___ \                           (_)       
\ `--.  _ __    __ _   ___   ___  | |_/ /  ___  _ __    __ _  _   _  _  _ __  
 `--. \| '_ \  / _` | / __| / _ \ |  __/  / _ \| '_ \  / _` || | | || || '_ \ 
/\__/ /| |_) || (_| || (__ |  __/ | |    |  __/| | | || (_| || |_| || || | | |
\____/ | .__/  \__,_| \___| \___| \_|     \___||_| |_| \__, | \__,_||_||_| |_|
       | |                                              __/ |                 
       |_|                                             |___/     
//////////////////////////////////////////////////////////////////////////////
 */
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

#define X first
#define Y second
#define int int_fast64_t
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define Compress(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define OOB(x, y) ((x) < 0 || (x) >= n || (y) < 0 || (y) >= m)
#define IDX(v, x) (lower_bound(all(v), x) - (v).begin())
#define debug(x) cout << (#x) << ": " << (x) << '\n'
#define sf1(a) cin >> a
#define sf2(a, b) cin >> a >> b
#define sf3(a, b, c) cin >> a >> b >> c
#define sf4(a, b, c, d) cin >> a >> b >> c >> d
#define sf5(a, b, c, d, e) cin >> a >> b >> c >> d >> e
#define sf6(a, b, c, d, e, f) cin >> a >> b >> c >> d >> e >> f
#define pf1(a) cout << (a) << ' '
#define pf2(a, b) cout << (a) << ' ' << (b) << ' '
#define pf3(a, b, c) cout << (a) << ' ' << (b) << ' ' << (c) << ' '
#define pf4(a, b, c, d) cout << (a) << ' ' << (b) << ' ' << (c) << ' ' << (d) << ' '
#define pf5(a, b, c, d, e) cout << (a) << ' ' << (b) << ' ' << (c) << ' ' << (d) << ' ' << (e) << ' '
#define pf6(a, b, c, d, e, f) cout << (a) << ' ' << (b) << ' ' << (c) << ' ' << (d) << ' ' << (e) << ' ' << (f) << ' '
#define pf0l() cout << '\n';
#define pf1l(a) cout << (a) << '\n'
#define pf2l(a, b) cout << (a) << ' ' << (b) << '\n'
#define pf3l(a, b, c) cout << (a) << ' ' << (b) << ' ' << (c) << '\n'
#define pf4l(a, b, c, d) cout << (a) << ' ' << (b) << ' ' << (c) << ' ' << (d) << '\n'
#define pf5l(a, b, c, d, e) cout << (a) << ' ' << (b) << ' ' << (c) << ' ' << (d) << ' ' << (e) << '\n'
#define pf6l(a, b, c, d, e, f) cout << (a) << ' ' << (b) << ' ' << (c) << ' ' << (d) << ' ' << (e) << ' ' << (f) << '\n'
#define rep(i, a, b) for (int i = a; i < b; i++)
#define pfvec(V)           \
for (auto const &t : V) \
pf1(t)
#define pfvecl(V)           \
for (auto const &t : V) \
pf1(t);             \
pf0l()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define Init(x, y) memset(x, y, sizeof(x));
#define EACH(x, a) for (auto& x: a)

using ll  = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;

using vi = vector<int>;
using vp = vector<pii>;
using vvi = vector<vi>;
using vvp = vector<vp>;
template <typename T>
using wector = vector<vector<T>>;
template <typename T>
using max_heap = priority_queue<T>;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> T max(vector<T> v) { return *max_element(all(v)); }

template<typename T>
void read(vector<T>& v){
EACH(i,v) sf1(i);
}

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
const int ddx[8] = {0, 0, 1, 1, 1, -1, -1, -1}, ddy[8] = {1, -1, 1, 0, -1, 1, 0, -1};
const int MOD = 1e9 + 7;
const double EPS = 1e-10;
const int INF = 1e9 + 7;

struct SegTree{
    int sz = 1 << 17;
    int tree[1 << 18];

    void Construct(){
        for(int i = sz - 1; i > 0; i--) tree[i] = max<int>(tree[i << 1], tree[i << 1 | 1]);
    }
    // Change ith element to val
    void Update(int i, int val){
        --i |= sz; tree[i] = val;
        while(i >>= 1) tree[i] = max<int>(tree[i << 1], tree[i << 1 | 1]);
    }

    int query(int L,int R,int nodeNum,int nodeL,int nodeR){
        if (R < nodeL || nodeR < L) return 0;
        if (L <= nodeL && nodeR <= R) return tree[nodeNum];
        int mid = nodeL + nodeR >> 1;
        return max<int>(query(L, R, nodeNum << 1, nodeL, mid), query(L, R, nodeNum << 1 | 1, mid + 1, nodeR));
    }

    int Query(int L,int R){
        return query(L, R, 1, 1, sz);
    }
};

struct _HLD{
    int n,cost[100'011];
    bool vist[100'011];
    int sz[100'011];
    int par[100'011];
    int top[100'011];
    int dep[100'011];
    int in[100'011];
    int out[100'011];

    vector<int> adj[100'011];
    vector<pii> inp[100'011],input;

    void DFS(int cur = 1){
        vist[cur] = 1;
        for(auto& [ncost, nxt] : inp[cur]){
            if(vist[nxt]) continue;
            cost[nxt] = ncost;
            adj[cur].push_back(nxt);
            DFS(nxt);
        }
    }

    void DFS1(int cur = 1){
        sz[cur] = 1;
        for(auto& nxt : adj[cur]){
            dep[nxt] = dep[cur] + 1; par[nxt] = cur;
            DFS1(nxt); sz[cur] += sz[nxt];
            if(sz[nxt] > sz[adj[cur][0]]) swap(nxt, adj[cur][0]);
        }
    }
    int temp;
    void DFS2(int cur = 1){
        in[cur] = ++temp;
        for(auto& nxt : adj[cur]){
            top[nxt] = (nxt == adj[cur][0] ? top[cur] : nxt);
            DFS2(nxt);
        }
        out[cur] = temp;
    }

    SegTree ST;
    void precalc(){
        cin >> n;
        for(int i = 1; i <= n - 1; i++){
            int a,b,c; sf3(a, b, c);
            input.push_back({a, b});
            inp[a].push_back({c, b});
            inp[b].push_back({c, a});
        }
        top[1] = 1;
        DFS(); DFS1(); DFS2();
        for(int i = 1; i <= n; i++){
            ST.tree[ST.sz - 1 + in[i]] = cost[i];
        }
        ST.Construct();
    }

    void HLDUpdate(int i, int val){
        ST.Update(in[i], val);
    }

    int LCA(int a,int b){
        while(top[a] != top[b]){
            if(dep[top[a]] < dep[top[b]]) swap(a, b);
            a = par[top[a]];
        }
        if(dep[a] > dep[b]) swap(a, b);
        return a;
    }
    // i번째 간선을 val로 바꿈
    void Update(int i, int val){
        auto& [a, b] = input[--i];
        if(dep[a] < dep[b]) swap(a, b);
        HLDUpdate(a, val);
    }

    // 경로 a - b에서 가장 가중치가 큰 간선
    int Query(int a,int b){
        int ret = 0;
        while(top[a] != top[b]){
            if(dep[top[a]] < dep[top[b]]) swap(a, b);
            int st = top[a];
            ret = max<int>(ret, ST.Query(in[st], in[a]));
            a = par[st];
        }
        if(a == b) return ret;
        if(dep[a] > dep[b]) swap(a, b);
        int nxt = -1;
        for(auto& i : adj[a]){
            if(top[i] == top[a]) nxt = i;
        }
        ret = max<int>(ret, ST.Query(in[nxt], in[b]));
        return ret;
    }
} HLD;

int32_t main(){
    fastio;
    HLD.precalc();
    int q; sf1(q);
    while(q--){
        int t,a,b; sf3(t, a, b);
        if(t == 1) HLD.Update(a, b);
        else pf1l(HLD.Query(a, b));
    }
    return 0;
}