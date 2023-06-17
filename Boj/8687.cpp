# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#define int int_fast64_t

using pt = pair<int, int>;
using tii = tuple<int, int, int>;

int board[1111][1111];
const int INF = int(2e9);
vector<vector<int>> dist(1111, vector<int>(1111, INF));
const int dx[3] = {-1, 1, 0};
const int dy[3] = {0, 0, 1};

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,m; cin >> n >> m;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> board[i][j];
	auto Bound = [&](int x, int y) -> bool{ return x < 0 or x >= n or y < 0 or y >= m; };
	priority_queue<tii, vector<tii>, greater<tii>> PQ;
	for(int i = 0; i < n; i++) if(!board[i][0]){
		dist[i][0] = 0;
		PQ.push({dist[i][0], i, 0});
	}
	while(PQ.size()){
		auto [cost, x, y] = PQ.top(); PQ.pop();
		if(y == m - 1){
			cout << cost << "\n";
			return 0;
		}
		if(dist[x][y] < cost) continue;
		for(int d = 0; d < 3; d++){
			auto nx = x + dx[d], ny = y + dy[d];
			if(Bound(nx, ny) or board[nx][ny]) continue;
			auto ncost = cost + (d != 2 ? 1 : 0);
			if(dist[nx][ny] > ncost + cost){
				dist[nx][ny] = ncost;
				PQ.push({dist[nx][ny], nx, ny});
			}
		}
	}
	cout << "NIE" << '\n';
    return 0; 
}
