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

const int PRECISION = 0;

int n,m;
auto bound = [](int x, int y ){ return x < 0 or x >= n or y < 0 or y >= m; };

void solve(){
    while(cin >> m >> n and m){
        vector<vector<int>> H(n, vector<int>(m));
        vector<vector<int>> W(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m - 1; j++) cin >> H[i][j];
            if(i < n - 1){
                for(int j = 0; j < m; j++) cin >> W[i][j];
            }
        }
        vector<vector<int>> dist(n + 1, vector<int>(m + 1, -1));
        queue<pair<int, int>> q;
        dist[0][0] = 1; q.push({0, 0});
        while(q.size()){
            auto [x, y] = q.front(); q.pop();
            if(y + 1 < m and !H[x][y] and dist[x][y + 1] == -1){
                dist[x][y + 1] = dist[x][y] + 1; q.push({x, y + 1});
            }
            if(y - 1 >= 0 and !H[x][y - 1] and dist[x][y - 1] == -1){
                dist[x][y - 1] = dist[x][y] + 1; q.push({x, y - 1});
            }
            if(x + 1 < n and !W[x][y] and dist[x + 1][y] == -1){
                dist[x + 1][y] = dist[x][y] + 1; q.push({x + 1, y});
            }
            if(x - 1 >= 0 and !W[x - 1][y] and dist[x - 1][y] == -1){
                dist[x - 1][y] = dist[x][y] + 1; q.push({x - 1, y});
            }
        }
        cout << (dist[n - 1][m - 1] == - 1 ? 0 : dist[n - 1][m - 1]) << "\n";
    }
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
