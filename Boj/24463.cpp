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
constexpr int INF = int(2e18);
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

using vi = vector<int>;
using vvi = vector<vi>;
using p = pair<int, int>;
using ti3 = tuple<int, int, int>;

int N, M;
vvi D(2020, vi(2020, INF));
string v[2020];
bool vist[2020][2020];
min_pq<ti3> PQ;

bool Bound(int x, int y){ return x < 0 or x >= N or y < 0 or y >= M; }

void Main(){
	ri(N, M);
	for(int i = 0; i < N; i++) ri(v[i]);
	int sx = -1,sy = -1, ex = -1, ey = -1;
	for(int i = 0; i < N; i++){
		if(v[i][0] == '.'){
			if(sx == -1) sx = i, sy = 0;
			else ex = i, ey = 0;
		}
		if(v[i][M - 1] == '.'){
			if(sx == -1) sx = i, sy = M - 1;
			else ex = i, ey = M - 1;
		}
	}
	for(int j = 0; j < M; j++){
		if(v[0][j] == '.'){
			if(sx == -1) sx = 0,sy = j;
			else ex = 0, ey = j;
		} 
		if(v[N - 1][j] == '.'){
			if(sx == -1) sx = N - 1,sy = j;
			else ex = N - 1, ey = j;
		}
	}
	PQ.push({D[sx][sy] = 0, sx, sy});
	while(SZ(PQ)){
		auto [cdist, x, y] = PQ.top(); PQ.pop();
		if(D[x][y] < cdist) continue;
		for(int d = 0; d < 4; d++){
			auto nx = x + dx[d], ny = y + dy[d];
			if(Bound(nx, ny) or v[nx][ny] == '+') continue;
			if(D[nx][ny] > cdist + 1){
				D[nx][ny] = cdist + 1;
				PQ.push({D[nx][ny], nx, ny});
			}
		}
	}
	int x = ex, y = ey;
	int E = D[ex][ey];
	while(1){
		if(x == sx and y == sy) break;
		vist[x][y] = 1;
		for(int d = 0; d < 4; d++){
			auto nx = x + dx[d], ny = y + dy[d];
			if(Bound(nx, ny) or v[nx][ny] == '+') continue;
			if(D[nx][ny] != D[x][y] - 1) continue;
			vist[nx][ny] = 1;		
			x = nx;
			y = ny;
		}
	}
	vist[x][y] = 1;
	vist[sx][sy] = 1; vist[ex][ey] = 1;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(v[i][j] == '.'){
				cout << (!vist[i][j] ? '@' : '.');
			}
			else cout << v[i][j];
		}
		cout << "\n";
	}
} 

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}
