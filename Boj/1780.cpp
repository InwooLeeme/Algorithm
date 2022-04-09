#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/rope>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using namespace __gnu_cxx;

#define X first
#define Y second
#define int int64_t
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define Compress(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define OOB(x, y) ((x) < 0 || (x) >= n || (y) < 0 || (y) >= m)
#define IDX(v, x) (lower_bound(all(v), x) - (v).begin())
#define debug(x) cout << (#x) << ": " << (x) << '\n'
#define sf1(a) cin >> a
#define sf2(a,b) cin >> a >> b
#define sf3(a,b,c) cin >> a >> b >> c
#define sf4(a,b,c,d) cin >> a >> b >> c >> d
#define sf5(a,b,c,d,e) cin >> a >> b >> c >> d >> e
#define sf6(a,b,c,d,e,f) cin >> a >> b >> c >> d >> e >> f
#define pf1(a) cout << (a) << ' '
#define pf2(a,b) cout << (a) << ' ' << (b) << ' '
#define pf3(a,b,c) cout << (a) << ' ' << (b) << ' '<< (c) << ' '
#define pf4(a,b,c,d) cout << (a) << ' ' << (b) << ' '<< (c) << ' '<< (d) << ' '
#define pf5(a,b,c,d,e) cout << (a) << ' ' << (b) << ' '<< (c) << ' '<< (d) << ' '<< (e) << ' '
#define pf6(a,b,c,d,e,f) cout << (a) << ' ' << (b) << ' '<< (c) << ' '<< (d) << ' '<< (e) << ' ' << (f) << ' '
#define pf0l() cout << '\n';
#define pf1l(a) cout << (a) << '\n'
#define pf2l(a,b) cout << (a) << ' ' << (b) << '\n'
#define pf3l(a,b,c) cout << (a) << ' ' << (b) << ' '<< (c) << '\n'
#define pf4l(a,b,c,d) cout << (a) << ' ' << (b) << ' '<< (c) << ' '<< (d) << '\n'
#define pf5l(a,b,c,d,e) cout << (a) << ' ' << (b) << ' '<< (c) << ' '<< (d) << ' '<< (e) << '\n'
#define pf6l(a,b,c,d,e,f) cout << (a) << ' ' << (b) << ' '<< (c) << ' '<< (d) << ' '<< (e) << ' ' << (f) << '\n'
#define pfvec(V) for(auto const &t : V) pf1(t)
#define pfvecl(V) for(auto const &t : V) pf1(t); pf0l()
#define rep(i, a, b) for(int i = a; i < b; i++)

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using tii = tuple<int, int, int>;
template <typename T>
using wector = vector<vector<T>>;
template <typename T>
using max_heap = priority_queue<T>;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int dx[4] = { 1,-1,0,0 };
const int dy[4] = { 0,0,1,-1 };
const int ddx[8] = { 0,0,1,1,1,-1,-1,-1 }, ddy[8] = { 1,-1,1,0,-1,1,0,-1 };

int n,t1,t2,t3;
int board[2190][2190];

// check n content is -1 or 0 or 1
bool Check(int n,int x,int y){
	rep(i,x,x + n){
		rep(j, y, y + n){
			if(board[i][j] != board[x][y]) return false;
		}
	}
	return true;
}

// DnC 
// 3씩 나눠가면서 분할 
void func(int n,int x,int y){
	if(Check(n,x,y)){ // base case
		if(board[x][y] == -1) t1++;
		else if(board[x][y] == 0) t2++;
		else if(board[x][y] == 1) t3++;
		return;
	}
	rep(i, 0, 3) rep(j, 0, 3) func(n / 3, x + i * n / 3, y + j * n / 3);
}

int32_t main(){
	fastio;
	sf1(n);
	rep(i,0,n) rep(j, 0, n) sf1(board[i][j]);
	func(n, 0, 0);
	pf1l(t1);
	pf1l(t2);
	pf1l(t3);
}