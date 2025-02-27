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
using vp = vector<p>;


int m,n, N;
int v[555][555];

int scc_cnt, dfs_cnt;
vvi G;
vector<int> scc, dfs_order;
stack<int> S;

void AddEdge(int a, int b) { G[a].push_back(b); }

int DFS(int cur) {
	int ret = dfs_order[cur] = ++dfs_cnt; S.push(cur);
	for (const auto& nxt : G[cur]) {
		if (!dfs_order[nxt]) ret = min(ret, DFS(nxt));
		else if (!scc[nxt]) ret = min(ret, dfs_order[nxt]);
	}
	if (ret == dfs_order[cur]) {
		for (scc_cnt++; S.size();) {
			int t = S.top(); S.pop();
			scc[t] = scc_cnt;
			if (t == cur) break;
		}
	}
	return ret;
}

void GetSCC() {
	for (int i = 1; i <= N; i++)
		if (!dfs_order[i]) DFS(i);
}

bool Bound(int x, int y){ return x < 0 or x >= n or y < 0 or y >= m; }

int Conv(int x, int y){ return x * m + y + 1; }

void Main(){
    ri(m, n);
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) ri(v[i][j]);
    N = n*m;
    G.resize(N + 1); scc.resize(N + 1);
    dfs_order.resize(N + 1);
    for(int x = 0; x < n; x++) for(int y = 0; y < m; y++){
        for(int d = 0; d < 4; d++){
            auto nx = x + dx[d], ny = y + dy[d];
            if(Bound(nx, ny)) continue;
            if(v[nx][ny] <= v[x][y]) AddEdge(Conv(x, y), Conv(nx, ny));  
        }
    }
    GetSCC();
    if(scc_cnt == 1){
        po(0);
        return;
    }
    vi indegree(N + 1), outdegree(N + 1);
    for(int i = 1; i <= N; i++){
        for(const auto& nxt : G[i]){
            if(scc[i] == scc[nxt]) continue;
            indegree[scc[nxt]]++;
            outdegree[scc[i]]++;
        }
    }
    int I = 0,O = 0;
    for(int i = 1; i <= scc_cnt; i++){
        I += (indegree[i] == 0);
        O += (outdegree[i] == 0);
    }
    po(max<int>(I, O));
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}
