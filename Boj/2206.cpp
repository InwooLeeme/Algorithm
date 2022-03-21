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
bool vist[1001][1001][2];
int dist[1001][1001] = {};
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

struct pos{
	int x,y,wall;
};


int32_t main(){
	fastio;
	int n,m; cin >> n >> m;
	bool flag = false;
	for(int i = 0; i < n; i++) cin >> board[i];
	queue<pos> Q;
	vist[0][0][0] = vist[0][0][1] = true;
	dist[0][0] = 1;
	Q.push({0,0,0});
	while(!Q.empty()){
		auto [curX,curY,wall] = Q.front(); Q.pop();
		if(curX == n - 1 && curY == m - 1){
			flag = true;
			break;
		}
		for(int i = 0; i < 4; i++){
			auto nx = curX + dx[i];
			auto ny = curY + dy[i];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // OOB
			if(board[nx][ny] == '1' && wall == 0 && !vist[nx][ny][wall + 1]){
				vist[nx][ny][wall + 1] = true;
				dist[nx][ny] = dist[curX][curY] + 1;
				Q.push({nx,ny,wall + 1});	
			}
			// Not wall Not visited
			if(board[nx][ny] == '0' && !vist[nx][ny][wall]){
				vist[nx][ny][wall] = true;
				dist[nx][ny] = dist[curX][curY] + 1;
				Q.push({nx,ny,wall});
			}
		}
	}
	cout << (flag ? dist[n - 1][m - 1] : -1) << "\n";
}