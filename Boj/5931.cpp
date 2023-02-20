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

int n,m;

int32_t main(){
    fastio;
    sf2(n, m); cin.ignore();
    vector<string> board(n);
    wector<int> dist(n + 1, vector<int>(m + 1, -1));
    wector<int> v(n + 1, vector<int>(m + 1, 0));
    auto oob = [&](int x,int y) -> bool{
        return x < 0 || x >= n || y < 0 || y >= m;
    };
    read(board);
    queue<pii> Q;
    // Indexing
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(dist[i][j] == -1 and board[i][j] == 'X'){
                dist[i][j] = 0;
                Q.push({i, j});
                cnt++;
                v[i][j] = cnt;
                while(!Q.empty()){
                    auto [x, y] = Q.front(); Q.pop();
                    for(int d = 0; d < 4; d++){
                        auto nx = x + dx[d],ny = y + dy[d];
                        if(oob(nx, ny) || board[nx][ny] == '.' || dist[nx][ny] != -1) continue;
                        dist[nx][ny] = dist[x][y] + 1;
                        v[nx][ny] = cnt;
                        Q.push({nx, ny});
                    }
                }
            }
        }
    }
    // BFS
    int mn = INF;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(v[i][j]){
                int cnt = 0;
                for(int d = 0; d < 4; d++){
                    auto x = i + dx[d], y = j + dy[d];
                    if(oob(x, y) || v[x][y] == v[i][j]) continue;
                    cnt++;
                }
                if(cnt >= 1){       
                    auto BFS = [&](int sx, int sy) -> int{
                        queue<pii> Q;
                        wector<int> dist(n + 1, vector<int>(m + 1, -1));
                        dist[sx][sy] = 0;
                        Q.push({sx, sy});
                        while(!Q.empty()){
                            auto [x, y] = Q.front(); Q.pop();
                            if(v[x][y] and v[sx][sy] != v[x][y]){
                                return dist[x][y];
                            }
                            for(int d = 0; d < 4; d++){
                                auto nx = x + dx[d],ny = y + dy[d];
                                if(oob(nx, ny) || dist[nx][ny] != -1 || v[nx][ny] == v[sx][sy]) continue;
                                dist[nx][ny] = dist[x][y] + 1;
                                Q.push({nx, ny});
                            }
                        }
                        return INF;
                    };
                    mn = min<int>(mn, BFS(i, j));
                }
            }
        }
    }
    pf1l(mn - 1);
    return 0;
}