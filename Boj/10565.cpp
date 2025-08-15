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

constexpr int SZ = 1 << 20;
int L[SZ<<1];
vector<int> Tmax(SZ<<1), Tmin(SZ<<1);

void Push(int node, int s, int e){
    if(L[node] == 0) return;
    Tmin[node] += L[node];
	Tmax[node] += L[node];
    if(s != e) L[node*2] += L[node], L[node*2+1] += L[node];
    L[node] = 0;
}

// [l, r]번째 수에 v를 더함, 0 <= l <= r < SZ
void RangeAdd(int l, int r, ll v, int node=1, int s=0, int e=SZ-1){
    Push(node, s, e);
    if(r < s || e < l) return;
    if(l <= s && e <= r){ L[node] += v; Push(node, s, e); return; }
    int m = (s + e) / 2;
    RangeAdd(l, r, v, node*2, s, m);
    RangeAdd(l, r, v, node*2+1, m+1, e);
	Tmin[node] = min<int>(Tmin[node * 2], Tmin[node*2+1]);
	Tmax[node] = max<int>(Tmax[node*2], Tmax[node*2+1]);
}

int Max(int l, int r, int node = 1, int s = 0, int e = SZ - 1){
	Push(node, s, e);
	if(r < s || e < l) return -INF;
	if(l <= s && e <= r) return Tmax[node];
	int m = (s + e) / 2;
	return max<int>(Max(l, r, node*2, s, m), Max(l, r, node*2+1, m+1, e));
}

int Min(int l, int r, int node = 1, int s = 0, int e = SZ - 1){
	Push(node, s, e);
	if(r < s || e < l) return INF;
	if(l <= s && e <= r) return Tmin[node];
	int m = (s + e) / 2;
	return min<int>(Min(l, r, node*2, s, m), Min(l, r, node*2+1, m+1, e));
}

void solve(){
	memset(L, 0, sizeof(L));
	fill(all(Tmin), 0);
	fill(all(Tmax), 0);
	int n,q; ri(n);
	vvi g(n + 1);
	for(int i = 2; i <= n; i++){
		int t; ri(t);
		g[t].pb(i);
	}
	vi v(n + 1); for(int i = 1; i <= n; i++) ri(v[i]);
	vi in(n + 1),out(n + 1);
	int temp = 0;
	auto dfs = [&](int cur, int par = -1, auto&& dfs) ->void{
		in[cur] = ++temp;
		for(const auto& nxt : g[cur]){
			if(nxt == par) continue;
			dfs(nxt, cur, dfs);
		}
		out[cur] = temp;
	};
	dfs(1, -1, dfs);
	for(int i = 1; i <= n; i++){
		RangeAdd(in[i], in[i], v[i]);
	}
	ri(q);
	while(q--){
		char c; ri(c);
		if(c == 'Q'){
			int x; ri(x);
			auto mn = Min(in[x], out[x]);
			auto mx = Max(in[x], out[x]);
			po(mx - mn);
		}
		else if(c == 'R'){
			int x, y; ri(x, y);
			RangeAdd(in[x], out[x], y);
		}
	}
}

void Main(){
	int t = 1; 
	ri(t);
	while(t--) solve();
	/* for(int tc = 1; tc <= t; tc++){
		cout << "Case #" << tc << ": "; solve();
	} */
}

int32_t main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed); cout.precision(PRECISION);
	Main();
	return 0;
}
