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

int n,m;
int board[1000][1000];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
const int INF = 1e9 + 7;

wector<int> dijk(pii st){
	wector<int> dist(n,vector<int>(m, INF));
	min_heap<tii> PQ;
	dist[st.X][st.Y] = board[st.X][st.Y];
	PQ.push({dist[st.X][st.Y], st.X, st.Y});
	while(!PQ.empty()){
		auto [cost, curX,curY] = PQ.top(); PQ.pop();
		if(dist[curX][curY] < cost) continue;
		for(int i = 0; i < 4; i++){
			auto nx = curX + dx[i];
			auto ny = curY + dy[i];
			auto ncost = cost + board[nx][ny];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(board[nx][ny] == -1) continue;
			if(dist[nx][ny] > ncost){
				dist[nx][ny] = ncost;
				PQ.push({dist[nx][ny], nx, ny});
			}
		}
	}
	return dist;
}

int32_t main(){
	fastio;
	cin >> n >> m;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> board[i][j];
	if(board[0][0] == -1){
		cout << -1 << "\n";
		return 0;
	}
	auto dist = dijk({0,0});
	cout << (dist[n - 1][m - 1] == INF ? -1 : dist[n - 1][m - 1]) << "\n";
}