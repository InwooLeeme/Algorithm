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

struct Player{
    int x,y,dps;
};

int n,m,p;
int curDps,BossHP;
vector<string> board;
map<int,Player> P;
deque<pii> DQ;
pii Boss;

void Input(){ // input
    sf3(n, m, p);
    board.resize(n);
    for(int i = 0; i < n; i++){
        sf1(board[i]);
        for(int j = 0; j < m; j++){
            if(board[i][j] == 'B') Boss = {i, j};
            else if(isalpha(board[i][j]) and islower(board[i][j])){ // player
                P[board[i][j] - 'a'] = {i, j, 0};
            }
        }
    }
    cin.ignore();
    for(int i = 0,t; i < p; i++){
        char c; sf2(c, t);
        P[i].dps = t;
    }
    sf1(BossHP);
}

bool Bound(int x,int y) { return x < 0 || x >= n || y < 0 || y >= m; }

int BFS(int idx){
    auto [sx, sy, dps] = P[idx];
    queue<pii> Q;
    wector<int> dist(n + 1, vi(m + 1, -1));
    Q.push({sx, sy});
    dist[sx][sy] = 0;
    while(!Q.empty()){
        auto [x, y] = Q.front(); Q.pop();
        if(x == Boss.first and y == Boss.second) return dist[x][y];
        for(int d = 0; d < 4; d++){
            auto nx = x + dx[d],ny = y + dy[d];
            if(Bound(nx, ny) || board[nx][ny] == 'X' || dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            Q.push({nx, ny});
        }
    }
    return INF;
}

void GoToBoss(){
    for(int i = 0; i < p; i++){
        int dist = BFS(i);
        DQ.push_back({dist, i});
    }
}

int Sol(){
    int cnt = 0;
    GoToBoss();
    sort(all(DQ), [&](pii& a, pii& b){
        return a.first == b.first ? P[a.second].dps < P[b.second].dps : a.first < b.first;
    });
    int time = 0;
    while(BossHP > 0){
        while(DQ.front().first == time){
            auto playerIdx = DQ.front().second;
            curDps += P[playerIdx].dps;
            DQ.pop_front();
            cnt++;
        }
        BossHP -= curDps;
        time++;
    }
    return cnt;
}

int32_t main(){
    fastio;
    Input();
    pf1l(Sol());
    return 0;
}