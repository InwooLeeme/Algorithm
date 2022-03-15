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

int board[5][5];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
set<string> S; // for unique

void dfs(int depth, int x, int y,string ret){
	ret += char(board[x][y]);
	if(depth == 5){ // base case
		S.insert(ret);
		return;
	}
	for(int i = 0; i < 4; i++){
		auto nx = x + dx[i];
		auto ny = y + dy[i];
		if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
		dfs(depth + 1, nx, ny, ret);
	}
}


int32_t main(){
	fastio;
	for(int i = 0; i < 5; i++) for(int j = 0; j < 5; j++) cin >> board[i][j];
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			dfs(0, i, j, "");
		}
	}
	cout << S.size() << "\n";
}