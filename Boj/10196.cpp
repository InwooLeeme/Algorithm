#pragma GCC target("avx,avx2,fma")
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

using p = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

const int PRECISION = 0;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};


int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    int t; cin >> t;
    for(int tc = 1; tc <= t; tc++){
    	cout << "Case: " << tc << "\n";
    	int n,m; cin >> n >> m;
    	vector<string> v(n); for(auto& i : v) cin >> i;
 		queue<p> Q;
		vvi dist(n + 1, vi(m + 1, -1));
		auto Bound = [&](int x, int y) -> bool { return x < 0 or x >= n or y < 0 or y >= m; };
		if(v[0][0] == 'O'){
			Q.push({0, 0}); dist[0][0] = 0;
		}
		while(Q.size()){
			auto [x, y] = Q.front(); Q.pop();
			for(int d = 0; d < 4; d++){
				auto nx = x + dx[d], ny = y + dy[d];
				if(Bound(nx, ny) or dist[nx][ny] != -1 or v[nx][ny] == 'X') continue;
				dist[nx][ny] = dist[x][y] + 1;
				Q.push({nx, ny});
			}			 
		} 
		auto Print = [&]() -> void{
			for(int i = 0; i < m; i++){
				cout << "+---";
			}
			cout << "+\n";
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					if(v[i][j] == 'X'){
						cout << "| X ";
					}
					else if(v[i][j] == 'O' and dist[i][j] == -1){
						cout << "|   ";
					}
					else if(v[i][j] == 'O' and dist[i][j] != -1){
						cout << "| M ";
					}
				}
				cout << "|\n";
				for(int j = 0; j < m; j++){
					cout << "+---";
				}
				cout << "+\n";
			}
		};
		Print();
		if(dist[n - 1][m - 1] != -1) cout << "Minions can cross the room\n";
		else cout << "Minions cannot cross the room\n";
	}
    return 0;
}
