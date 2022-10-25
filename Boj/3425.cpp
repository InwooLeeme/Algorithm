//////////////////////////////////////////////////////////////////////////////
/* 
 _____                            ______                             _        
/  ___|                           | ___ \                           (_)       
\ `--.  _ __    __ _   ___   ___  | |_/ /  ___  _ __    __ _  _   _  _  _ __  
 `--. \| '_ \  / _` | / __| / _ \ |  __/  / _ \| '_ \  / _` || | | || || '_ \ 
/\__/ /| |_) || (_| || (__ |  __/ | |    |  __/| | | || (_| || |_| || || | | |
\____/ | .__/  \__,_| \___| \___| \_|     \___||_| |_| \__, | \__,_||_||_| |_|
       | |                                              __/ |                 
       |_|                                             |___/     
//////////////////////////////////////////////////////////////////////////////
 */
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
#define int int64_t
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define Compress(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define OOB(x, y) ((x) < 0 || (x) >= n || (y) < 0 || (y) >= m)
#define IDX(v, x) (lower_bound(all(v), x) - (v).begin())
#define debug(x) cout << (#x) << ": " << (x) << '\n'
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

template<typename T>
void read(vector<T>& v){
EACH(i,v) sf1(i);
}

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
const int ddx[8] = {0, 0, 1, 1, 1, -1, -1, -1}, ddy[8] = {1, -1, 1, 0, -1, 1, 0, -1};
const int M = 1e9 + 7;
const double EPS = 1e-10;
const int INF = 1e9 + 7;

int DIV(int a, int b) {
	int flag = (a < 0) ^ (b < 0);
	int ret = abs(a) / abs(b);
	return flag ? -ret : ret;
}

int MOD(int a, int b) {
	int flag = (a < 0);
	int ret = abs(a) % abs(b);
	return flag ? -ret : ret;
}

int32_t main(){
    fastio;
    while(1){
        vector<pair<string,int>> v;
        while(1){
            string s; sf1(s);
            if(s == "END") break;
            if(s == "QUIT") return 0;
            v.push_back({s, 0});
            if(s == "NUM") sf1(v.back().second);
        }
        auto Sol = [&](int st) -> int {
			stack<int> S; S.push(st);
			for (const auto& [a, b] : v) {
				if (a == "NUM") S.push(b);
				else if (a == "POP") {
					if (S.empty()) return INF;
					S.pop();
				}
				else if (a == "INV") {
					if (S.empty()) return INF;
					int t = S.top(); S.pop();
					S.push(-t);
				}
				else if (a == "DUP") {
					if (S.empty()) return INF;
					S.push(S.top());
				}
				else if (a == "SWP") {
					if (S.size() < 2) return INF;
					int a = S.top(); S.pop();
					int b = S.top(); S.pop();
					S.push(a); S.push(b);
				}
				else if (a == "ADD") {
					if (S.size() < 2) return INF;
					int a = S.top(); S.pop();
					int b = S.top(); S.pop();
					if (abs(a + b) > 1e9) return INF;
					S.push(a + b);
				}
				else if (a == "SUB") {
					if (S.size() < 2) return INF;
					int a = S.top(); S.pop();
					int b = S.top(); S.pop();
					if (abs(b - a) > 1e9) return INF;
					S.push(b - a);
				}
				else if (a == "MUL") {
					if (S.size() < 2) return INF;
					int a = S.top(); S.pop();
					int b = S.top(); S.pop();
					if (abs(1.l * a * b) > 1e9) return INF;
					S.push(a * b);
				}
				else if (a == "DIV") {
					if (S.size() < 2) return INF;
					int a = S.top(); S.pop();
					int b = S.top(); S.pop();
					if (a == 0) return INF;
					S.push(DIV(b, a));
				}
				else if (a == "MOD") {
					if (S.size() < 2) return INF;
					int a = S.top(); S.pop();
					int b = S.top(); S.pop();
					if (a == 0) return INF;
					S.push(MOD(b, a));
				}
			}
			return S.size() == 1 ? S.top() : INF;
		};

        int n; sf1(n);
        while(n--){
            int t; sf1(t);
            auto ret = Sol(t);
            if(ret < INF) pf1l(ret);
            else pf1l("ERROR");
        }
        pf0l();
    }
}