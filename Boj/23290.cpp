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
#define si(x) (int)x.size()
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
using minpq = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using maxpq = priority_queue<T>;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R>
using ordered_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R>
using ordered_multimap = tree<T, R, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> bool chmin(T& a, const T& b){ return a > b ? a = b, 1 : 0; }
template<class T> bool chmax(T& a, const T& b){ return a < b ? a = b, 1 : 0; }
template<class T, class U> bool chmin(T& a, const U& b){ return a > b ? a = b, 1 : 0; }
template<class T, class U> bool chmax(T& a, const U& b){ return a < b ? a = b, 1 : 0; }
template<class T> void rev(T& a){ reverse(all(a)); }
template<class T> void uniq(T& a){ sor(a); a.erase(unique(all(a)), end(a)); }


const int PRECISION = 1;
constexpr int INF = 1LL * 1 << 60;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using pii = pair<int, int>;
using ti3 = tuple<int, int, int>;
using vp = vector<pii>;
using vs = vector<string>;

ll popcnt(unsigned long long a){ return __builtin_popcountll(a); }
ll intpow(ll a, ll b){ ll ans = 1; while(b){ if(b & 1) ans *= a; a *= a; b /= 2; } return ans; }
ll modpow(ll a, ll b, ll p){ ll ans = 1; while(b){ if(b & 1) (ans *= a) %= p; (a *= a) %= p; b /= 2; } return ans; }


struct Shark{
	int x,y,d;
} shark;

int N = 4, M, S;
vvvi fish(5, vvi(5));
int Smell[5][5];


bool bound(int x, int y){ return x < 0 or x >= N or y < 0 or y >= N; }

void Input(){
	memset(Smell, -1, sizeof(Smell));
	ri(M, S);
	for(int i = 0; i < M; i++){
		int a,b,c; ri(a, b, c); --a,--b,--c;
		fish[a][b].pb(c);
	}
	ri(shark.x, shark.y); --shark.x, --shark.y;
}

vvvi Copy(){
	vvvi res(5, vvi(5));
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++){
		if(fish[i][j].empty()) continue;
		for(const auto& d : fish[i][j]) res[i][j].push_back(d);
	}
	return res;
}

bool IsShark(int x, int y){ return x == shark.x and y == shark.y; }
bool IsSmell(int x, int y){ return Smell[x][y] != -1; }

void FishMove(){
	const int fx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
	const int fy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
	auto Possible = [&](int x, int y) -> bool{
		return !(bound(x, y) or IsShark(x, y) or IsSmell(x, y));
	};
	// move
	vvvi board(5, vvi(5));
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++){
		for(const auto& d : fish[i][j]){
			int curd = d; bool moving = 0;
			// rotate dirs
			for(int _ = 0; _ < 8; _++){
				int nx = i + fx[curd], ny = j + fy[curd];
				if(Possible(nx, ny)){
					moving = 1;
					board[nx][ny].push_back(curd);
					break;
				}
				curd = (curd + 7) % 8;
			}
			if(!moving) board[i][j].push_back(d);
		}
	}
	// Update Fish Board
	fish.swap(board);
}

void SharkMove(int shark_move_idx){
	const int fx[4] = {-1, 0, 1, 0};
	const int fy[4] = {0, -1, 0, 1};
	int best_cnt = -1;
	array<int, 3> good = {0, 0, 0};
	for(int d1 = 0; d1 < 4; d1++){
		int nx1 = shark.x + fx[d1], ny1 = shark.y + fy[d1];
		if(bound(nx1, ny1)) continue;
		for(int d2 = 0; d2 < 4; d2++){
			int nx2 = nx1 + fx[d2], ny2 = ny1 + fy[d2];
			if(bound(nx2, ny2)) continue;
			for(int d3 = 0; d3 < 4; d3++){
				int nx3 = nx2 + fx[d3], ny3 = ny2 + fy[d3];
				if(bound(nx3, ny3)) continue;
				bool vist[4][4]{};
				int cnt = 0;
				if(!vist[nx1][ny1]){
					cnt += si(fish[nx1][ny1]);
					vist[nx1][ny1] = 1;
				}
				if(!vist[nx2][ny2]){
					cnt += si(fish[nx2][ny2]);
					vist[nx2][ny2] = 1;
				}
				if(!vist[nx3][ny3]){
					cnt += si(fish[nx3][ny3]);
					vist[nx3][ny3] = 1;
				}
				if(cnt > best_cnt){
					best_cnt = cnt;
					good = {d1, d2, d3};
				}
			}
		} 
	}
	int x = shark.x, y = shark.y;
	for(int _ = 0; _ < 3; _++){
		int d = good[_];
		int nx = x + fx[d], ny = y + fy[d];
		if(si(fish[nx][ny])){
			fish[nx][ny].clear();
			Smell[nx][ny] = shark_move_idx;
		}
		x = nx, y = ny;
	}
	shark.x = x, shark.y = y;
}

void RemoveFishSmell(int shark_move_idx){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(Smell[i][j] == shark_move_idx - 2){
				Smell[i][j] = -1;
			}
		}
	}
}

void UpdateFishBoard(vvvi& v){
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++){
		if(v[i][j].empty()) continue;
		for(const auto& d : v[i][j]){
			fish[i][j].push_back(d);
		}
	}
}

int GetFish(){
	int res = 0;
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) res += si(fish[i][j]);
	return res;
}

void Magic(){
	for(int magic_cnt = 1; magic_cnt <= S; magic_cnt++){
		auto copyfish = Copy(); // 1
		FishMove();
		SharkMove(magic_cnt);
		RemoveFishSmell(magic_cnt);
		UpdateFishBoard(copyfish);
	}
}

void solve(){
	Input();
	Magic();
	po(GetFish());
}

void Main(){
	int t = 1; 
	//ri(t);
	while(t--) solve();
	/* for(int tc = 1; tc <= t; tc++){
		cout << "Case #" << tc << ": "; solve();
	} */
}

int32_t main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed); cout.precision(PRECISION);
	Main();
	return 0;
}
