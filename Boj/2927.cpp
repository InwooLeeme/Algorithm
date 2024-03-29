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

using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
using vp = vector<pii>;
using vvp = vector<vp>;
using vs = vector<string>;
using vvs = vector<vs>;
using ti3 = tuple<int,int,int>;
using vti3 = vector<ti3>;

template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_pq = priority_queue<T>;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename V, class cmp = less<T>>
using ordered_map = tree<T, V, cmp, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T>
void printv(vector<T> v) {
	for (auto e : v) {
		cout << e << " ";
	}   cout << "\n";
}
 
template<typename T>
void printvv(vector<T> vv) {
	for (int i=0; i<vv.size(); i++) {
		cout << i << ": ";
		for (auto e : vv[i]) {
			cout << e << " ";
		}   cout << "\n";
	}
}

template<typename T>
void ri(T &x) {
	cin >> x;
}
template<typename T, typename... Args>
void ri(T &x, Args&... args) {
	ri(x);
	ri(args...) ;
}
template<typename T>
void ri(vector<T> &v) {
	for (auto &x : v) {
		cin >> x;
	}
}
template<typename T, typename... Args>
void ri(vector<T> &v, Args&... args) {
	ri(v);
	ri(args...);
}

template<typename T>
void po(T x) {
	cout << x << "\n";
}
template<typename T, typename... Args>
void po(T x, Args... args) {
	cout << x << " ";
	po(args...) ;
}
template<typename T>
void po(vector<T> &a) {
	for (int i=0; i<(int)a.size(); i++) {
		if (i <(int)a.size()-1) {
			cout << a[i] << " ";
		}
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

int cnt_leq_x(vi &a, int x) {
	return upper_bound(a.begin(), a.end(), x) - a.begin();
}

int cnt_leq_x(vi &a, int x, int lo, int hi) {
	return upper_bound(a.begin()+lo, a.begin()+hi, x) - a.begin()+lo;
}

int cnt_lt_x(vi &a, int x) {
	return lower_bound(a.begin(), a.end(), x) - a.begin();
}

int cnt_lt_x(vi &a, int x, int lo, int hi) {
	return lower_bound(a.begin()+lo, a.begin()+hi, x) - a.begin()+lo;
}

int cnt_geq_x(vi &a, int x) {
	return a.end() - lower_bound(a.begin(), a.end(), x);
}

int cnt_geq_x(vi &a, int x, int lo, int hi) {
	return a.begin()+hi - lower_bound(a.begin()+lo, a.begin()+hi, x);
}

int cnt_gt_x(vi &a, int x) {
	return a.end() - upper_bound(a.begin(), a.end(), x);
}

int cnt_gt_x(vi &a, int x, int lo, int hi) {
	return a.begin()+hi - upper_bound(a.begin()+lo, a.begin()+hi, x);
}

bool mul_overflow(int a, int b) {
	int c;
	return __builtin_mul_overflow(a, b, &c);
}

template<typename T>
int popcount(T x) {return __builtin_popcount(x);}

template<typename T>
T sum(vector<T> &a) {
	T ret = 0;
	for (auto v : a) ret += v;
	return ret;
}

template<typename T>
T max(vector<T> &a) {
	return *max_element(a.begin(), a.end());
}

template<typename T>
T min(vector<T> &a) {
	return *min_element(a.begin(), a.end());
}

int ceil_div(int a, int b) {
	return (a + b - 1) / b;
}

int int_pow(int base, int exp) {
	int res = 1;
	while (exp) {
		if (exp & 1) res *= base;
		exp >>= 1;
		base *= base;
	}
	return res;
}

int highest_power_of_2(int n) {
	while((n & (n-1)) != 0){
		n = n & (n-1);
	}
	return n;
}

int msb_pos(int x) {
	if (x==0) return -1;
	int y = __builtin_clzll(x);
	int ret = 63 - y;
	return ret;
}

template<typename T>
void chmax(T &x, T y) {x = max(x,y);}

template<typename T>
void chmin(T &x, T y) {x = min(x,y);}

template<typename T>
void asort(vector<T> &a) {sort(a.begin(), a.end());}

template<typename T>
void dsort(vector<T> &a) {sort(a.rbegin(), a.rend());}

template<typename T>
void reverse(vector<T> &a) {reverse(a.begin(), a.end());}

template<typename T>
set<T> get_set(vector<T> &a) {
	set<T> ret(a.begin(), a.end());
	return ret;
}

template<typename T>
vector<T> get_unique(vector<T> a) {
	asort(a);
	a.erase(unique(a.begin(), a.end()), a.end());
	return a;
}

vs Split(string& s){
	string temp; 
	vs ret;
	stringstream in(s);
	while(in >> temp) ret.push_back(temp);
	return ret;
}

int LIS(vi& v){
	vi LIS;
	for(auto& i : v){
		if(LIS.empty() or LIS.back() < i) LIS.push_back(i);
		else *lower_bound(LIS.begin(), LIS.end(), i) = i;
	}
	return LIS.size();
}

int LDS(vi& v){
	vi LDS;
	for(auto& i : v){
		auto t = -i;
		if(LDS.empty() or LDS.back() < t) LDS.push_back(t);
		else *lower_bound(LDS.begin(), LDS.end(), t) = t;
	}
	return LDS.size();
}

int _pow(int x, int n){
    int ret = 1;
    while(n){
        if(n & 1) ret = ret * x;
        x = x * x;
        n >>= 1;
    }
    return ret;
}

constexpr int INF = int(2e18);

const int PRECISION = 0;

struct UnionFind{
	vector<int> par;
	UnionFind(int n):par(n){
		iota(par.begin(), par.end(), 0);
	}

	int Find(int x){ return x == par[x] ? x : par[x] = Find(par[x]); }
	bool Union(int a, int b){
		a = Find(a),b = Find(b);
		if(a == b) return 0;
		par[b] = a;
		return 1;
	}
	void Clear(){
		iota(par.begin(), par.end(), 0);
	}
};

struct SegTree{
	int sz = 1 << 17;
	vector<int> tree;
	
	SegTree():tree(sz << 1){}

	void Build(){
		for(int i = sz; i >= 1; i--) tree[i] = tree[i << 1] + tree[i << 1 | 1];
	}
	
	void Update(int i, int val){
		i |= sz; tree[i] = val;
		while(i >>= 1) tree[i] = tree[i << 1] + tree[i << 1 | 1];
	}

	int Query(int l, int r){
		int ret = 0;
		l |= sz, r |= sz;
		while(l <= r){
			if(l & 1) ret += tree[l++];
			if(~r & 1) ret += tree[r--];
			l >>= 1; r >>= 1;
		}
		return ret;
	}
} ST;

struct query{ string s; int a,b; };

struct HLD{
	int in[1 << 17], out[1 << 17], top[1 << 17], dep[1 << 17], sz[1 << 17], par[1 << 17];
	vector<int> G[1 << 17], inp[1 << 17];

	bitset<1 << 17> vist;
	void DFS(int cur = 1){
		vist[cur] = 1;
		for(auto& nxt : inp[cur]){
			if(vist[nxt]) continue;
			G[cur].push_back(nxt);
			DFS(nxt);
		}
	}

	void DFS1(int cur = 1){
		sz[cur] = 1;
		for(auto& nxt : G[cur]){
			dep[nxt] = dep[cur] + 1; par[nxt] = cur;
			DFS1(nxt); sz[cur] += sz[nxt];
			if(sz[nxt] > sz[G[cur][0]]) swap(nxt, G[cur][0]);
		}
	}
	
	int temp;
	void DFS2(int cur = 1){
		in[cur] = ++temp;
		for(auto& nxt : G[cur]){
			top[nxt] = (nxt == G[cur][0] ? top[cur] : nxt);
			DFS2(nxt);
		}
		out[cur] = temp;
	}
} _HLD;

void Update(int i, int val){
	ST.Update(_HLD.in[i], val);
}

int Query(int a, int b){
	int ret = 0;
	while(_HLD.top[a] != _HLD.top[b]){
		if(_HLD.dep[_HLD.top[a]] < _HLD.dep[_HLD.top[b]]) swap(a, b);
		int st = _HLD.top[a];
		ret += ST.Query(_HLD.in[st], _HLD.in[a]);
		a = _HLD.par[st];
	}
	if(_HLD.dep[a] > _HLD.dep[b]) swap(a, b);
	ret += ST.Query(_HLD.in[a], _HLD.in[b]);
	return ret;
}

void Main(){
    int n,q; ri(n);
	vi v(n + 1);
	for(int i = 1; i <= n; i++) ri(v[i]);
	UnionFind UF(30303);
	ri(q);
	vector<query> Q;
	while(q--){
		string s; int a,b; ri(s, a, b);
		Q.push_back({s, a, b});
		if(s == "bridge" and UF.Union(a, b)){
			_HLD.inp[a].push_back(b); _HLD.inp[b].push_back(a);
		}
	}
	for(int i = 1; i <= n; i++){
		if(UF.Union(1, i)) _HLD.inp[1].push_back(i), _HLD.inp[i].push_back(1);
	}
	_HLD.top[1] = _HLD.dep[1] = 1;
	_HLD.DFS(1); _HLD.DFS1(1); _HLD.DFS2(1);
	for(int i = 1; i <= n; i++) Update(i, v[i]);
	ST.Build();
	UF.Clear();
	for(auto& [s, a, b] : Q){
		if(s == "bridge"){
			if(UF.Union(a, b)) po("yes");
			else po("no");
		}
		else if(s == "penguins") Update(a, b);
		else{
			if(UF.Find(a) != UF.Find(b)) po("impossible");
			else po(Query(a, b));
		}
	}
}

int32_t main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed); cout.precision(PRECISION);
	Main();
	return 0;
}
