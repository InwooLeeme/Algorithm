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

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int board[101][101];
bool vist[101][101];
int n,m;

void dfs(int x,int y){
	vist[x][y] = true;
	for(int i = 0; i < 4; i++){
		auto nx = x + dx[i];
		auto ny = y + dy[i];
		if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // OOB
		if(vist[nx][ny] || board[nx][ny] == 0) continue;
		dfs(nx ,ny);
	}
}

void reset(){
	for(int i = 0; i < 101; i++){
		fill(board[i],board[i] + 101,0);
		fill(vist[i],vist[i] + 101,false);
	}
}

int32_t main(){
	fastio;
	int t; cin >> t;
	while(t--){
		reset();
		cin >> n >> m;
		int components = 0;
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
			char c; cin >> c;
			if(c == '#') board[i][j] = 1;
			else board[i][j] = 0;
		}
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
			if(!vist[i][j] && board[i][j]){
				components++;
				dfs(i, j);
			}
		}
		cout << components << "\n";
	}
}