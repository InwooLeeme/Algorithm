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

const int PRECISION = 0;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

constexpr int INF = int(2e18);

// Directed Graph이면 add_edge(s, e, c)
// Undirected Graph이면 add_edge(s, e, c, c)
template<typename flow_t, flow_t MAX_U=(1<<30)>
struct Dinic{ // 0-based
  struct edge_t{ int v, r; flow_t c, f; };
  int n;
  vector<vector<edge_t>> g;
  vector<int> lv, idx;
  Dinic(int n) : n(n) { clear(); }
  void clear(){
    g = vector<vector<edge_t>>(n);
    lv = vector<int>(n, 0);
    idx = vector<int>(n, 0);
  }
  void add_edge(int s, int e, flow_t c1, flow_t c2=flow_t(0)){
    g[s].push_back({e, (int)g[e].size(), c1, 0});
    g[e].push_back({s, (int)g[s].size()-1, c2, 0});
  }
  bool bfs(int s, int t, flow_t limit=1){
    fill(lv.begin(), lv.end(), 0);
    queue<int> que; que.push(s); lv[s] = 1;
    while(!que.empty()){
      int v = que.front(); que.pop();
      for(const auto &e : g[v]) if(!lv[e.v] && e.c - e.f >= limit) que.push(e.v), lv[e.v] = lv[v] + 1;
    }
    return lv[t] != 0;
  }
  flow_t dfs(int v, int t, flow_t fl=MAX_U){
    if(v == t || fl == flow_t(0)) return fl;
    for(int &i=idx[v]; i<g[v].size(); i++){
      auto &e = g[v][i];
      if(lv[e.v] != lv[v] + 1 || e.c - e.f == flow_t(0)) continue;
      flow_t now = dfs(e.v, t, min(fl, e.c - e.f));
      if(now == flow_t(0)) continue;
      e.f += now; g[e.v][e.r].f -= now;
      return now;
    }
    return 0;
  }
  flow_t maximum_flow(int s, int t){
    flow_t flow = 0, augment = 0;
    while(bfs(s, t)){
      fill(idx.begin(), idx.end(), 0);
      while((augment=dfs(s, t)) != flow_t(0)) flow += augment;
    }
    return flow;
  }
  // {최소 컷 비용, s와 같은 집합, t와 같은 집합, 절단 간선}
  tuple<flow_t, vector<int>, vector<int>, vector<pair<int,int>>> minimum_cut(int s, int t){
    flow_t flow = maximum_flow(s, t);
    vector<int> a, b;
    vector<pair<int,int>> edges;
    bfs(s, t, 1);
    for(int i=0; i<n; i++) (lv[i] ? a : b).push_back(i);
    for(auto i : a) for(auto e : g[i]) if(e.c != flow_t(0) && !lv[e.v]) edges.emplace_back(i, e.v);
    return {flow, a, b, edges};
  }
};

int N, M;
bool Bound(int x, int y){ return x < 0 or x >= N or y < 0 or y >= M; }
string board[111];

int in(int x){ return x; }
int out(int x){ return N*M + x; }
int Conv(int x, int y){ return x * M + y; }

void Main(){
    ri(N, M);
    for(int i = 0; i < N; i++) ri(board[i]);
    for(int i = 0; i < N; i++) for(int j = 0; j < M; j++){
      if(board[i][j] != 'K') continue;
      for(int d = 0; d < 4; d++){
        auto nx = i + dx[d], ny = j + dy[d];
        if(Bound(nx, ny)) continue;
        if(board[nx][ny] == 'H'){
          po(-1);
          return;
        }
      }
    }
    int S = -1, E = -1;
    Dinic<int> flow(((N*M) << 1) + 10);
    for(int i = 0; i < N; i++) for(int j = 0; j < M; j++){
      flow.add_edge(in(Conv(i, j)), out(Conv(i, j)), 1);
      if(board[i][j] == '#') continue;
      if(board[i][j] == 'K') S = out(Conv(i, j));
      else if(board[i][j] == 'H') E = in(Conv(i, j));
      for(int d = 0; d < 4; d++){
        auto nx = i + dx[d], ny = j + dy[d];
        if(Bound(nx, ny)) continue;
        if(board[nx][ny] == '#') continue;
        auto cur = Conv(i, j),nxt = Conv(nx, ny);
        flow.add_edge(out(cur), in(nxt), INF);
      }
    }
    auto ret = flow.maximum_flow(S, E);
    po(ret);
}   

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}
