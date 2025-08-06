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
#define si(x) (int)x.size()
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
using minpq = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using maxpq = priority_queue<T>;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R>
using ordered_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R>
using ordered_multimap = tree<T, R, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> bool chmin(T& a, const T& b){ return a > b ? a = b, 1 : 0; }
template<class T> bool chmax(T& a, const T& b){ return a < b ? a = b, 1 : 0; }
template<class T, class U> bool chmin(T& a, const U& b){ return a > b ? a = b, 1 : 0; }
template<class T, class U> bool chmax(T& a, const U& b){ return a < b ? a = b, 1 : 0; }
template<class T> void rev(T& a){ reverse(all(a)); }
template<class T> void uniq(T& a){ sor(a); a.erase(unique(all(a)), end(a)); }


const int PRECISION = 0;
constexpr int INF = int(2e18);
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using pii = pair<int, int>;
using ti3 = tuple<int, int, int>;
using vp = vector<pii>;
using vs = vector<string>;

ll popcnt(unsigned long long a){ return __builtin_popcountll(a); }
ll intpow(ll a, ll b){ ll ans = 1; while(b){ if(b & 1) ans *= a; a *= a; b /= 2; } return ans; }
ll modpow(ll a, ll b, ll p){ ll ans = 1; while(b){ if(b & 1) (ans *= a) %= p; (a *= a) %= p; b /= 2; } return ans; }

int n,m;

struct unionfind{
	vi P;
	unionfind(int n):P(n + 1){
		iota(all(P), 0);
	}
	int Find(int x){ return x == P[x] ? x : P[x] = Find(P[x]);	}
	bool Union(int a, int b){
		a = Find(a),b = Find(b);
		if(a == b) return 0; P[b] = a; return 1;
	}
};

struct node{
	int mx,smx;
	node():mx(-1),smx(-1){}
	node(int x):mx(x),smx(-1){}
	node(int x, int y){
		mx = max<int>(x, y);
		smx = (mx == x ? y : x);		
	};
};

node operator+(node a, node b){
	vector<int> v{a.mx, a.smx, b.mx, b.smx};
	sort(rall(v));
	v.erase(unique(all(v)), v.end());
	while(si(v) < 2) v.pb(-1);
	return {v[0], v[1]};
};

template<typename T>
struct segtree{
	const int sz = 1 << 17;
	vector<T> tree;
	segtree():tree(sz << 1, T()){}
	void Update(int i, T val){
		--i |= sz; tree[i] = val;
		while(i >>= 1) tree[i] = tree[i << 1] + tree[i << 1 | 1];
	}
	T Query(int l, int r){
		--l |= sz; --r |= sz;
		T ret;
		while(l <= r){
			if(l & 1) ret = ret + tree[l++];
			if(~r & 1) ret = ret + tree[r--];
			l >>= 1, r >>= 1;
		}
		return ret;
	}
};

const int SZ = 1 << 17;
int Top[SZ], Par[SZ], Dep[SZ], Sz[SZ], In[SZ], cost[SZ];
vp Inp[SZ];
vector<int> G[SZ];
segtree<node> seg;

void Connect(int u, int v, int c){
    Inp[u].push_back({c, v}); Inp[v].push_back({c, u});
}

void DFS0(int v, int b = -1){
    for(auto [c, i] : Inp[v]) if(i != b){
    	Dep[i] = Dep[v] + 1, Par[i] = v, cost[i] = c, G[v].push_back(i), DFS0(i, v);
	}
}

void DFS1(int v){
    Sz[v] = 1;
    for(auto &i : G[v]){
        DFS1(i); Sz[v] += Sz[i];
        if(Sz[i] > Sz[G[v][0]]) swap(i, G[v][0]);
    }
}

void DFS2(int v){
    static int pv = 0; In[v] = ++pv;
    for(auto i : G[v]) Top[i] = i == G[v][0] ? Top[v] : i, DFS2(i);
}

node query(int u, int v){
   	node res;
    for(; Top[u] != Top[v]; u=Par[Top[u]]){
        if(Dep[Top[u]] < Dep[Top[v]]) swap(u, v);
        res = res + seg.Query(In[Top[u]], In[u]);
    }
    if(In[u] > In[v]) swap(u, v);
    res = res + seg.Query(In[u] + 1, In[v]); 
    return res;
}

tuple<int, int, vector<ti3>, vector<ti3>> MST(vector<ti3>& e){
	int cnt = 0,cost = 0;
	vector<ti3> use, unuse;
	unionfind uf(n + 1);
	for(const auto& [c, a, b] : e){
		if(uf.Union(a, b)){
			++cnt;
			cost += c;
			Connect(a, b, c);
			use.pb({c, a, b});
		}
		else unuse.pb({c, a, b});
	}
	return {cnt, cost, use, unuse};
}

void solve(){
	ri(n, m);
	vector<ti3> e(m);
	for(auto& [c, a, b] : e) ri(a, b, c);
	sort(all(e));
	auto [cnt, mst, use, unuse] = MST(e);
	//debug(cnt, cost, useE, unuseE);
	if(cnt != n - 1){
		po(-1);
		return;
	}
	// hld
	DFS0(1); DFS1(1); DFS2(Top[1] = 1);
	for(int i = 1; In[i]; i++){
		//debug(In[i]);
		seg.Update(In[i], cost[i]);
	}
	int res = INF;
	for(const auto& [c, a, b] : unuse){
		auto [mx, smx] = query(a, b);
		if(smx != -1){
			res = min<int>(res, mst - smx + c);
		}
		if(mx != -1 and c != mx){
			res = min<int>(res, mst - mx + c);
		}
		//debug(mx, smx, c);
	}
	//debug(res, mst);
	if(res <= mst or res == INF) po(-1);
	else po(res);
}

void Main(){
    int t = 1; 
    //ri(t);
    while(t--) solve();
}

int32_t main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout.setf(ios::fixed); cout.precision(PRECISION);
  Main();
  return 0;
}
