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
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

using vi = vector<int>;
using vvi = vector<vi>;
using p = pair<int, int>;
using ti3 = tuple<int, int, int>;

const int dx3[6] = {1, 0, -1, 0, 0, 0};
const int dy3[6] = {0, 1, 0, -1, 0, 0};
const int dz3[6] = {0, 0, 0, 0, 1, -1};

int N, M, K;
char board[7][7][7];
int I[7][7][7], par[1010], match[1010];
vi G[1010];
bool vist[7][7][7];

bool Bound(int x, int y, int z){ return x < 0 or x >= N or y < 0 or y >= M or z < 0 or z >= K; }

void AddEdge(int a, int b){ G[a].pb(b); }

void C(){
    memset(I, -1, sizeof(I));
    memset(vist, 0, sizeof(vist));
    memset(par, -1, sizeof(par));
    memset(match, 0, sizeof(match));
    for(int i = 0; i < 7; i++) for(int j = 0; j < 7; j++) for(int k = 0; k < 7; k++) board[i][j][k] = '.';
    for(int i = 0; i < 1010; i++) G[i].clear();
}

void DFS(int x, int y, int z, int Comp = 1){
    vist[x][y][z] = 1;
    I[x][y][z] = Comp;
    for(int d = 0; d < 4; d++){
        auto nx = x + dx[d], ny = y + dy[d];
        if(Bound(nx, ny, z)) continue;
        if(board[nx][ny][z] == '#' or vist[nx][ny][z]) continue;
        DFS(nx, ny, z, Comp);
    }
}

int Match(int cur){
    for(const auto& nxt : G[cur]){
        if(match[nxt]) continue;
        match[nxt] = 1;
        if(par[nxt] == -1 or Match(par[nxt])){
            par[nxt] = cur;
            return 1;
        }
    }
    return 0;
}

void Sol(){
    C();
    ri(N, M, K);
    for(int h = 0; h < K; h++) for(int r = 0; r < N; r++) for(int c = 0; c < M; c++) ri(board[r][c][h]);
    // DFS Ordering
    int idx = 1;
    for(int h = 0; h < K; h++) for(int r = 0; r < N; r++) for(int c = 0; c < M; c++){
        if(vist[r][c][h] or board[r][c][h] == '#') continue;
        DFS(r, c, h, idx);
        idx++;
    }
    // Add Edge
    for(int h = 0; h < K; h += 2){
        for(int x = 0; x < N; x++) for(int y = 0; y < M; y++){
            if(board[x][y][h] == '#') continue;
            auto cur = I[x][y][h];
            for(const auto& d : {1, -1}){
                auto nx = x, ny = y, nz = h + d;
                if(Bound(nx, ny, nz) or board[nx][ny][nz] == '#' or I[nx][ny][nz] == -1) continue;
                auto nxt = I[nx][ny][nz];
                AddEdge(cur, nxt);
                
            }
        }
    }
    int ret = 0;
    for(int i = 1; i < idx; i++){
        memset(match, 0, sizeof(match));
        ret += Match(i);
    }
    po(idx - 1 - ret);
}

void Main(){
    int t; ri(t);
    for(int tc = 1; tc <= t; tc++){
        cout << "Case #" << tc << ": "; 
        Sol();
    }
}   

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}
