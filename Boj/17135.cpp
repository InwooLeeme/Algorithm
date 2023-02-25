# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
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
#define SZ(v) (int)(v).size()
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
#define pfvec(V)            \
	for (auto const &t : V) \
	pf1(t)
#define pfvecl(V)           \
	for (auto const &t : V) \
		pf1(t);             \
	pf0l()
#define pfvecll(V)           \
	for (auto const &t : V) \
		pf1l(t);             \
	pf0l()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define EACH(x, a) for (auto& x: a)

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using tii = tuple<int, int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
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
template<typename T> T sz(vector<T> v) { return (int)v.size(); }

template<typename T>
void read(vector<T>& v){
	EACH(i,v) sf1(i);
}

template<typename T>
void print(T arg) {
	cout << arg << '\n';
}

template<typename T, typename... Types>
void print(T arg, Types... args) {
	cout << arg << " ";
	print(args...);
}
template<typename T>
void debug(T arg){
    cout << "(" << "#" << arg << ")" << ": " << arg << '\n';
}
template<typename T, typename... Types>
void debug(T arg, Types... args){
    cout << "(" << "#" << arg << ")" << ": " << arg << ' ';
    debug(args...);
}

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
const int ddx[8] = {0, 0, 1, 1, 1, -1, -1, -1}, ddy[8] = {1, -1, 1, 0, -1, 1, 0, -1};
const int MOD = 1e9 + 7;
const long double EPS = 1e-12;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1);

int n,m,d; 
int board[17][17];

int Sol(int a,int b,int c){
    int cnt = 0;
    int xPos = n + 1;
    array<int, 3> yPos = {a, b, c};
    int board2[17][17];
    int check[17][17];
    constexpr int kdx[3] = {0, -1, 0};
    constexpr int kdy[3] = {-1, 0, 1};
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++){
        board2[i][j] = board[i][j];
        check[i][j] = 0;
    }
    while(xPos > 1){
        for(auto& yP : yPos){
            wector<int> dist(17, vector<int>(17, -1));
            queue<pii> Q;
            Q.push({xPos - 1, yP});
            dist[xPos][yP] = 0;
            while(!Q.empty()){
                auto x = Q.front().first,y = Q.front().second; Q.pop();
                if(board2[x][y]){
                    check[x][y] = 1;
                    break;
                }
                for(int k = 0; k < 3; k++){
                    auto nx = x + kdx[k],ny = y + kdy[k];
                    if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
                    if(dist[nx][ny] != -1) continue;
                    if(abs(nx - xPos) + abs(ny - yP) > d) continue;
                    dist[nx][ny] = dist[x][y] + 1;
                    Q.push({nx, ny});
                }
            }
        }
        for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++){
            if(check[i][j]) board2[i][j] = 0;
        }
        xPos--;
    }
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) if(check[i][j]) cnt++;
    return cnt;
}

int32_t main(){
	fastio;
    // input
    sf3(n, m, d);
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) sf1(board[i][j]);
    int mx = 0;
    for(int i = 1; i <= m; i++){
        for(int j = i + 1; j <= m; j++){
            for(int k = j + 1; k <= m; k++){
                mx = max(mx, Sol(i, j, k));
            }
        }
    }
    pf1l(mx);
	return 0; 
}
