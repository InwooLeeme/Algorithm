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
#define int int64_t
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

struct SegTree {
	ll tree[1 << 21], lazy[1 << 21]; //arr[0, n-1] -> tree[sz, sz + n - 1]
	int sz = 1 << 20;

	void construct() {
		for (int i = sz - 1; i > 0; i--) {
			tree[i] = tree[i << 1] + tree[i << 1 | 1];
		}
	}
	void propagate(int node, int nodeL, int nodeR) {
		if (lazy[node]) {
			if (node < sz) {
				lazy[node << 1] += lazy[node];
				lazy[node << 1 | 1] += lazy[node];
			}
			tree[node] += lazy[node] * (nodeR - nodeL + 1);
			lazy[node] = 0;
		}
	}
	//[l, r] += k
	void update(int L, int R, int k, int nodeNum, int nodeL, int nodeR) {
		propagate(nodeNum, nodeL, nodeR);
		if (R < nodeL || nodeR < L) return;
		if (L <= nodeL && nodeR <= R) {
			lazy[nodeNum] += k;
			propagate(nodeNum, nodeL, nodeR);
			return;
		}
		int mid = nodeL + nodeR >> 1;
		update(L, R, k, nodeNum << 1, nodeL, mid);
		update(L, R, k, nodeNum << 1 | 1, mid + 1, nodeR);
		tree[nodeNum] = tree[nodeNum << 1] + tree[nodeNum << 1 | 1];
	}
	void update(int l, int r, int k) {
		update(l, r, k, 1, 1, sz);
	}
	//[l, r] : 1-indexed
	ll query(int L, int R, int nodeNum, int nodeL, int nodeR) {
		propagate(nodeNum, nodeL, nodeR);
		if (R < nodeL || nodeR < L) return 0;
		if (L <= nodeL && nodeR <= R) return tree[nodeNum];
		int mid = nodeL + nodeR >> 1;
		return query(L, R, nodeNum << 1, nodeL, mid) + query(L, R, nodeNum << 1 | 1, mid + 1, nodeR);
	}
	ll query(int l, int r) {
		return query(l, r, 1, 1, sz);
	}
} ST;


int32_t main(){
    fastio;
    int n,m; sf2(n, m);
    for(int i = 0; i < n; i++){
        int t; sf1(t);
        ST.tree[ST.sz + i] = t;
    }
    ST.construct();
    while(m--){
        int a,b,c; sf3(a, b, c); //--a,--b;
        ST.update(a, b, c);
    }
    for(int i = 1; i <= n; i++) pf1(ST.query(i, i));
}