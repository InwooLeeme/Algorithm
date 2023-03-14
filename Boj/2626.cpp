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

const int MOD = 1e9 + 7;
const double EPS = 1e-10;
const int INF = 0x7f7f7f7f;

struct p { double x, y; };

double dis(p a, p b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int32_t main(){
    fastio;
    int N; sf1(N);
    vector<p> v(N);
    for(int i=0; i<N; i++) sf2(v[i].x, v[i].y);
    p cen = {0, 0};
    double r = 0;
    for(int i=0; i<N; i++) {
        if(dis(cen, v[i]) <= r) continue;
        cen = v[i], r = 0;
        for(int j=0; j<i; j++) {
            if(dis(cen, v[j]) <= r) continue;
            cen = {(v[i].x + v[j].x) / 2, (v[i].y + v[j].y) / 2};
            r = dis(cen, v[i]);
            for(int k=0; k<j; k++) {
                if(dis(cen, v[k]) <= r) continue;
                cen.x = ((pow(v[j].x, 2) - pow(v[k].x, 2) + pow(v[j].y, 2) - pow(v[k].y, 2)) * (v[i].y - v[j].y)
                         - (pow(v[j].x, 2) - pow(v[i].x, 2) + pow(v[j].y, 2) - pow(v[i].y, 2)) * (v[k].y - v[j].y))
                         / ((v[i].x - v[j].x) * (v[k].y - v[j].y) * 2 - (v[k].x - v[j].x) * (v[i].y - v[j].y) * 2);
                cen.y = ((pow(v[j].y, 2) - pow(v[k].y, 2) + pow(v[j].x, 2) - pow(v[k].x, 2)) * (v[i].x - v[j].x)
                         - (pow(v[j].y, 2) - pow(v[i].y, 2) + pow(v[j].x, 2) - pow(v[i].x, 2)) * (v[k].x - v[j].x))
                         / ((v[i]. y- v[j].y) * (v[k].x - v[j].x) * 2 - (v[k].y - v[j].y) * (v[i].x - v[j].x) * 2);
                r = dis(cen, v[i]);
            }
        }
    }
    if(abs(cen.x) < 1e-4) cen.x = 0;
    if(abs(cen.y) < 1e-4) cen.y = 0;
    cout << fixed << setprecision(3) << cen.x << " " << cen.y << "\n";
    cout << r << "\n";
    return 0;
}