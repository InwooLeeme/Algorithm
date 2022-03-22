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

string board[1001];
int n,m,k,dist[1001][1001][11];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

struct Pos{
	int x,y,broken;
};

int bfs(){
	queue<Pos> Q;
	dist[0][0][0] = 1;
	Q.push({0,0,0});
	while(!Q.empty()){
		auto [curX, curY, t] = Q.front(); Q.pop();
		if(curX == n - 1 && curY == m - 1) return dist[curX][curY][t];
		for(int i = 0; i < 4; i++){
			auto nx = curX + dx[i];
			auto ny = curY + dy[i];
			if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue; // OOB
			auto nt = t + (board[nx][ny] == '1');
			if(nt > k || dist[nx][ny][nt]) continue;
			dist[nx][ny][nt] = dist[curX][curY][t] + 1;
			Q.push({nx, ny, nt});
		}
	}
	return -1;
}

int32_t main(){
	fastio;
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++) cin >> board[i];
	cout << bfs() << "\n";
}