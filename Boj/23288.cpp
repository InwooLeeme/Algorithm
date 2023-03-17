#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
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
const int INF = 0x7f7f7f7f;

int n,m,k,dir = 0,ans,x = 1,y = 1;
int board[22][22];
int v[7]; // cube

bool Bound(int x,int y) { return x < 1 || x > n || y < 1 || y > m; }
bool IsBound(int x, int y, int d){
    if(d == 0) return Bound(x, y + 1); // 동
    else if(d == 1) return Bound(x + 1, y); // 남
    else if(d == 2) return Bound(x, y - 1); // 서
    return Bound(x - 1, y); // 북
}

int BFS(int stx,int sty){
    int ret = 0;
    wector<int> dist(n + 1, vi(m + 1, -1));
    queue<pii> Q;
    dist[stx][sty] = 0;
    Q.push({stx, sty});
    while(!Q.empty()){
        auto x = Q.front().first,y = Q.front().second; Q.pop();
        for(int d = 0; d < 4; d++){
            auto nx = x + dx[d],ny = y + dy[d];
            if(Bound(nx, ny) || dist[nx][ny] != -1 || board[nx][ny] != board[stx][sty]) continue;
            dist[nx][ny] = dist[x][y] + 1;
            Q.push({nx, ny});
        }
    }
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) if(dist[i][j] != -1) ret++;
    return ret;
}

// 동
void R(){
    int temp = v[6];
    v[6] = v[3];
    v[3] = v[1];
    v[1] = v[4];
    v[4] = temp;
}
// 서
void L(){
    int temp = v[4];
    v[4] = v[1];
    v[1] = v[3];
    v[3] = v[6];
    v[6] = temp;
}
// 북
void N(){
    int temp = v[6];
    v[6] = v[5];
    v[5] = v[1];
    v[1] = v[2];
    v[2] = temp;
}
// 남
void D(){
    int temp = v[5];
    v[5] = v[6];
    v[6] = v[2];
    v[2] = v[1];
    v[1] = temp;
}

void Move(){
    // 경계에서 벗어났는지 확인후에 이동방향 바꾸고 1칸 이동
    if(IsBound(x, y, dir)){ // 현재 가려는 방향이 board에서 벗어난 곳인가?
        if(dir == 0) dir = 2;
        else if(dir == 1) dir = 3;
        else if(dir == 2) dir = 0;
        else if(dir == 3) dir = 1;
    }
    if(dir == 0){ // 동
        R();
        y += 1;
    }
    else if(dir == 1){ // 남
        D();
        x += 1;
    }
    else if(dir == 2){ // 서
        L();
        y -= 1;
    }
    else if(dir == 3){
        N();
        x -= 1;
    }
    // Get Score
    int B = board[x][y], C = BFS(x, y);
    ans += (B * C);
    // 방향 변경?
    if(v[6] == B) return;
    else if(v[6] > B) dir = ((dir + 1) % 4);
    else if(v[6] < B) dir = ((dir - 1 + 4) % 4);
}

int32_t main(){
    fastio;
    // Input
    sf3(n, m, k);
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) sf1(board[i][j]);
    v[1] = 1,v[5] = 2,v[2] = 5,v[3] = 3,v[4] = 4,v[6] = 6;
    while(k--) Move();
    pf1l(ans);
    return 0;
}