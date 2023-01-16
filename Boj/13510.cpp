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

template<size_t _sz>
struct HLD {
	SegTree ST;
	vector<int> cost, sz, dep, par, top, in, out;
	vector<vector<pair<int, int>>> inp;
	vector<vector<int>> adj;
	HLD() : cost(_sz), sz(_sz), dep(_sz), par(_sz), top(_sz), in(_sz), out(_sz), inp(_sz), adj(_sz) {}
	void add_edge(int a, int b, int c) { inp[a].push_back({ b, c }), inp[b].push_back({ a, c }); }
	void dfs(int cur = 1, int prev = -1) {
		for (auto [nxt, ncost] : inp[cur]) {
			if (nxt == prev) continue;
			adj[cur].push_back(nxt);
			cost[nxt] = ncost;
			dfs(nxt, cur);
		}
	}
	void dfs1(int cur = 1) {
		sz[cur] = 1;
		for (auto& nxt : adj[cur]) {
			dep[nxt] = dep[cur] + 1; par[nxt] = cur;
			dfs1(nxt); sz[cur] += sz[nxt];
			if (sz[nxt] > sz[adj[cur][0]]) swap(nxt, adj[cur][0]);
		}
	}
	int temp = 0;
	void dfs2(int cur = 1) {
		in[cur] = ++temp;
		for (auto nxt : adj[cur]) {
			top[nxt] = (nxt == adj[cur][0] ? top[cur] : nxt);
			dfs2(nxt);
		}
		out[cur] = temp;
	}
	void construct() {
		dfs(), dfs1(), dfs2(top[1] = 1);
		for (int i = 1; in[i]; i++) ST.Update(in[i], cost[i]);
	}
	int path_query(int a, int b) {
		int ret = -INF;
		for (; top[a] ^ top[b]; a = par[top[a]]) {
			if (dep[top[a]] < dep[top[b]]) swap(a, b);
			ret = max(ret, ST.Query(in[top[a]], in[a]));
		}
		if (dep[a] > dep[b]) swap(a, b);
		ret = max(ret, ST.Query(in[a] + 1, in[b]));
		return ret;
	}
	void node_update(int x, int val) {
		ST.Update(in[x], val);
	}
};

HLD<1 << 17> hld;

struct Info{
    int x,y,z;
};

int32_t main(){
    fastio;
    int n; cin >> n;
    vector<Info> v(n - 1);
    for(int i = 0; i < n -1; i++){
        auto& [a, b, c] = v[i]; cin >> a >> b >> c;
		hld.add_edge(a, b, c);
    }
    hld.construct();
    int q; sf1(q);
    while(q--){
        int t,a,b; cin >> t >> a >> b;
        if(t == 1){
            int t1 = v[a - 1].x,t2 = v[a - 1].y;
            if(hld.dep[t1] < hld.dep[t2]) swap(t1, t2);
            hld.node_update(t1, b);
        }
        else pf1l(hld.path_query(a, b));
    }
    return 0;
}