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

const int INF = int(2e18);

using vi = vector<int>;
using vvi = vector<vi>;
using p = pair<int, int>;

int N, M;
string v[111];

vvi BFS(int r, int c){
    vvi D(N + 1, vi(M + 1, -1));
    queue<p> Q; Q.push({r, c}); D[r][c] = 0;
    while(SZ(Q)){
        auto [x, y] = Q.front(); Q.pop();
        for(int d = 0; d < 4; d++){
            auto nx = x + dx[d], ny = y + dy[d];
            if(nx < 0 or nx >= N or ny < 0 or ny >= M) continue;
            if(D[nx][ny] != -1 or v[nx][ny] == '1') continue;
            D[nx][ny] = D[x][y] + 1; Q.push({nx, ny});
        }
    }
    return D;
}

void Main(){
    ri(N, M);
    for(int i = 0; i < N; i++) ri(v[i]);
    p a,b,c; ri(a.fi, a.se, b.fi, b.se, c.fi, c.se); --a.fi,--a.se, --b.fi, --b.se, --c.fi,--c.se;
    auto D1 = BFS(a.fi, a.se);
    auto D2 = BFS(b.fi, b.se);
    auto D3 = BFS(c.fi, c.se);
    int cnt = 0,mn = INF;
    for(int i = 0; i < N; i++) for(int j = 0; j < M; j++){
        if(v[i][j] == '1' or D1[i][j] == -1 or D2[i][j] == -1 or D3[i][j] == -1) continue;
        mn = min<int>(mn, max<int>({D1[i][j], D2[i][j],D3[i][j]}));
        //debug(D1[i][j], D2[i][j], D3[i][j]);
    }
    for(int i = 0; i < N; i++) for(int j = 0; j < M; j++){
        if(v[i][j] == '1' or D1[i][j] == -1 or D2[i][j] == -1 or D3[i][j] == -1) continue;
        if(max<int>({D1[i][j], D2[i][j],D3[i][j]}) == mn) cnt++;
    }
    if(mn == INF){
        po(-1);
        return;
    }
    po(mn); po(cnt);
}   

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}
