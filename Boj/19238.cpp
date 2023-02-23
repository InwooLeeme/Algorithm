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
#define int int_fast64_t
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define Compress(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define OOB(x, y) ((x) < 0 || (x) >= n || (y) < 0 || (y) >= m)
#define IDX(v, x) (lower_bound(all(v), x) - (v).begin())
#define SZ(x) (x).size()
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
#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))

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
template<typename T> T min(vector<T> v) { return *min_element(all(v)); }

template<typename T>
void read(vector<T>& v){
EACH(i,v) sf1(i);
}

template<typename T>
void debug(T arg){
    cout << arg << "\n";
}
template<typename T, typename... Types>
void debug(T arg, Types... args) {
    cout << arg << "\n";
    debug(args...);
}

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
const int ddx[8] = {0, 0, 1, 1, 1, -1, -1, -1}, ddy[8] = {1, -1, 1, 0, -1, 1, 0, -1};
const int MOD = 1e9 + 7;
const double EPS = 1e-10;
const int INF = 0x3f3f3f3f;

struct Customer{
    int dist, px,py,dstx,dsty;
    Customer():dist(0),px(0),py(0),dstx(0),dsty(0){};
    Customer(int di ,int a,int b,int c,int d):dist(di),px(a),py(b),dstx(c),dsty(d){}
};

int n,m,fuel,tx,ty;
int board[22][22], dist[22][22];
pii en[444];
int st[22][22];

bool oob(int x,int y) { return x < 0 || x >= n || y < 0 || y >= n; }

void BFS(int sx, int sy){
    for(int i = 0; i < n; i++) fill(dist[i], dist[i] + 22, -1);
    queue<pii> Q;
    dist[sx][sy] = 0;
    Q.push({sx ,sy});
    while(!Q.empty()){
        auto& [x, y] = Q.front(); Q.pop();
        for(int d = 0; d < 4; d++){
            auto nx = x + dx[d],ny = y + dy[d];
            if(oob(nx, ny) || dist[nx][ny] != -1 || board[nx][ny]) continue;
            dist[nx][ny] = dist[x][y] + 1;
            Q.push({nx, ny});
        }
    }
}

int32_t main(){
    fastio;
    // input
    sf3(n, m, fuel);
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) sf1(board[i][j]);
    sf2(tx, ty); // taxi pos 
    --tx,--ty;
    for(int i = 1; i <= m; i++){
        int a,b,c,d; sf4(a, b, c, d); --a,--b,--c,--d;
        st[a][b] = i;
        en[i] = {c, d};
    }
    while(m--){
        if(st[tx][ty]);
        else{
            BFS(tx, ty);
            int nx = -1,ny = -1, mx = INF;
            for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
                if(st[i][j] == 0 || mx <= dist[i][j] || dist[i][j] == -1) continue;
                mx = dist[i][j];
                nx = i,ny = j;
            }
            if(nx == -1 || fuel < dist[nx][ny]){
                pf1l(-1);
                return 0;
            }
            tx = nx, ty = ny;
            fuel -= dist[nx][ny];
        }
        if(make_pair(tx, ty) == en[st[tx][ty]]){
            st[tx][ty] = 0;
        }
        else{
            BFS(tx, ty);
            int nx,ny;
            for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
                if(make_pair(i, j) == en[st[tx][ty]]) nx = i,ny = j;
            }
            if(dist[nx][ny] == -1 || fuel < dist[nx][ny]){
                pf1l(-1);
                return 0;
            }
            st[tx][ty] = 0;
            tx = nx,ty = ny;
            fuel += dist[nx][ny];
        }
    }
    pf1l(fuel);
    return 0;
}