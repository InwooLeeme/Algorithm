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
using p = pair<int, int>;
using ti3 = tuple<int, int, int>;

// n: 왼쪽 정점 개수, m: 오른쪽 정점 개수, 0-based
struct HopcroftKarp{
  int n, m;
  vector<vector<int>> g;
  vector<int> dst, le, ri;
  vector<char> visit, track;
  HopcroftKarp(int n, int m) : n(n), m(m) { clear(); }
  void clear(){
    g = vector<vector<int>>(n); dst = vector<int>(n, 0);
    le = vector<int>(n, -1); ri = vector<int>(m, -1);
    visit = vector<char>(n, 0); track = vector<char>(n+m, 0);
  }
  void add_edge(int s, int e){ g[s].push_back(e); }
  bool bfs(){
    bool res = false;
    queue<int> que;
    fill(dst.begin(), dst.end(), 0);
    for(int i=0; i<n; i++) if(le[i] == -1) que.push(i), dst[i] = 1;
    while(!que.empty()){
      int v = que.front(); que.pop();
      for(auto i : g[v]){
        if(ri[i] == -1) res = true;
        else if(!dst[ri[i]]) dst[ri[i]] = dst[v] + 1, que.push(ri[i]);
      }
    }
    return res;
  }
  bool dfs(int v){
    if(visit[v]) return false;
    visit[v] = 1;
    for(auto i : g[v]){
      if(ri[i] == -1 || !visit[ri[i]] && dst[ri[i]] == dst[v] + 1 && dfs(ri[i])){
        le[v] = i; ri[i] = v; return true;
      }
    }
    return false;
  }
  int maximum_matching(){
    int res = 0;
    fill(le.begin(), le.end(), -1);
    fill(ri.begin(), ri.end(), -1);
    while(bfs()){
      fill(visit.begin(), visit.end(), 0);
      for(int i=0; i<n; i++) if(le[i] == -1) res += dfs(i);
    }
    return res;
  }
  vector<pair<int,int>> maximum_matching_edges(){
    int matching = maximum_matching();
    vector<pair<int,int>> edges; edges.reserve(matching);
    for(int i=0; i<n; i++) if(le[i] != -1) edges.emplace_back(i, le[i]);
    return edges;
  }
  void dfs_track(int v){
    if(track[v]) return; track[v] = 1;
    for(auto i : g[v]) track[n+i] = 1, dfs_track(ri[i]);
  }
  tuple<vector<int>, vector<int>, int> minimum_vertex_cover(){
    int matching = maximum_matching();
    fill(track.begin(), track.end(), 0);
    for(int i=0; i<n; i++) if(le[i] == -1) dfs_track(i);
    vector<int> lv, rv;
    for(int i=0; i<n; i++) if(!track[i]) lv.push_back(i);
    for(int i=0; i<m; i++) if(track[n+i]) rv.push_back(i);
    assert(lv.size() + rv.size() == matching);
    return {lv, rv, lv.size() + rv.size()};
  }
};

int N;
int A[202020], B[202020], CA[202020], CB[202020];

void Main(){
	ri(N);
	for(int i = 1; i <= N; i++){
		int a,b,c,d; ri(a, b, c, d);
		A[i] = a, CA[i] = b, B[i] = c, CB[i] = d;
	}
	auto Check = [&](const int mid) -> bool{
		HopcroftKarp flow(N + 1, (N << 1) + 2);
		for(int i = 1; i <= N; i++){
			if(CA[i] <= mid) flow.add_edge(i, A[i]);
			if(CB[i] <= mid) flow.add_edge(i, B[i]);
		}
		auto ret = flow.maximum_matching();
		return ret != N;
	};
	const int END = int(1e6) + 1;
	int L = -1, R = END;
	while(L + 1 < R){
		int mid = L + R >> 1;
		if(Check(mid)) L = mid;
		else R = mid;
	}
	po((R == END) ? -1 : R);
}   

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}
