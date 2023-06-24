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

#define int int_fast64_t

using pt = pair<int, int>;

const int dx[8] = {1, 2, 1, 2, -2, -1, -2, -1};
const int dy[8] = {2, 1, -2, -1, 1, 2, -1, -2};

int32_t main(){
	fastio;
	int n,m;
	pt s,e;
	while(cin >> n >> m){
		cin >> s.first >> s.second >> e.first >> e.second;
		auto Bound = [&](int x, int y) -> bool { return x <= 0 or x > n or y <= 0 or y > m; };
		auto Sol = [&]() -> int{
			queue<pt> Q;
			vector<vector<int>> dist(n + 1, vector<int>(m + 1, -1));
			dist[e.first][e.second] = 0;
			Q.push(e);
			while(Q.size()){
				auto [x, y] = Q.front(); Q.pop();
				if(x == s.first and y == s.second) return dist[x][y];
				for(int d = 0; d < 8; d++){
					auto nx = x + dx[d], ny = y + dy[d];
					if(Bound(nx, ny) or dist[nx][ny] != -1) continue;
					dist[nx][ny] = dist[x][y] + 1;
					Q.push({nx, ny});
				}
			}
			return -1;
		};
		auto ret = Sol();
		if(ret == -1) cout << "impossible" << "\n";
		else cout << ret << "\n";
	}
	return 0;
}