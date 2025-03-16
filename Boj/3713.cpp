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

struct two_sat{
	int n,c,scc_cnt;
	vector<vector<int>> adj;
	vector<int> disc,scc;
	stack<int> S;
	vector<bool> answer;
	two_sat(int n = 0):
		n(n),c(0),disc(n + 1 << 1, 0),scc_cnt(0),
		scc(n + 1 << 1, 0),adj(n + 1 << 1){}
	
	int DFS(int cur){
		S.push(cur);
		disc[cur] = ++c;
		int ret = disc[cur];
		for(auto nxt : adj[cur]){
			if(!disc[nxt]) ret = min(ret, DFS(nxt));
			else if(!scc[nxt]) ret = min(ret, disc[nxt]);
		}
		if(ret == disc[cur]){
			scc_cnt++;
			while(S.size()){
				int h = S.top(); S.pop();
				scc[h] = scc_cnt;
				if(h == cur) break;
			}
		}
		return ret;
	}

	void Add_Edge(int a, bool na, int b, bool nb){
		// (x1 ∨ x2) -> ¬x1 → x2, ¬x2 → x1
		// a << 1 | na : ¬a
		// a << 1 : a
		a = a << 1 | na;
		b = b << 1 | nb;
		adj[a ^ 1].push_back(b);
		adj[b ^ 1].push_back(a);
	}
	
	bool isSatisified(){
		for(int i = 1; i < (n + 1 << 1); i++){
			if(!disc[i]) DFS(i);
		}
		for(int i = 1; i <= n; i++){
			if(scc[i << 1] == scc[i << 1 | 1]) return false;	
			answer.push_back((scc[i << 1] < scc[i << 1 | 1]));
		}
		return true;
	}
	
	vector<bool> get_answer(){ return answer; }
};

void Sol(){
	int n; ri(n);
	struct I{ int h; char g; string music,sports; };
	vector<I> l, r;
	for(int i = 0; i < n; i++){
		int h; char c; string a,b; ri(h, c, a, b);
		(c == 'M' ? l : r).pb({h, c, a, b});
	}
	auto Check = [&](I& a, I& b) -> bool{
		return (abs(a.h - b.h) <= 40 and a.g != b.g and a.music == b.music and a.sports != b.sports);
	};
	vi match(n), par(n, -1);
	vvi g(n);
	auto add_edge = [&](int a, int b) -> void{ g[a].pb(b); };
	for(int i = 0; i < SZ(l); i++) for(int j = 0; j < SZ(r); j++){
		if(Check(l[i], r[j])) add_edge(i, j);
	}
	auto dfs = [&](int cur, auto&& dfs) -> int{
		for(const auto& nxt : g[cur]){
			if(match[nxt]) continue;
			match[nxt] = 1;
			if(par[nxt] == -1 or dfs(par[nxt], dfs)){
				par[nxt] = cur;
				return 1;
			}
		}
		return 0;
	};
	int res = 0;
	for(int i = 0; i < SZ(l); i++){
		fill(all(match), 0);
		res += dfs(i, dfs);
	}
	po(n - res);
}

void Main(){
	int t; ri(t); while(t--) Sol();
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}
