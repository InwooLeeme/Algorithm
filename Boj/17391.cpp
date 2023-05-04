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

using pt = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n,m; cin >> n >> m;
    vvi board(n + 1, vi(m + 1)),dist(n + 1, vi(m + 1, -1));
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> board[i][j];
    auto Bound = [&](int x, int y) -> int{ return x < 0 || x >= n || y < 0 || y >= m; };
    queue<pt> Q;
    Q.push({0, 0});
    dist[0][0] = 0;
    const int dx[2] = {0, 1};
    const int dy[2] = {1, 0};
    while(Q.size()){
        auto [x, y] = Q.front(); Q.pop();
        if(x == n - 1 and y == m - 1){
            cout << dist[x][y] << "\n";
            return 0;
        }
        auto l = board[x][y];
        for(int d = 0; d < 2; d++){
            for(int k = 1; k <= l; k++){
                auto nx = x + k * dx[d], ny = y + k * dy[d];
                if(Bound(nx, ny) or dist[nx][ny] != -1) continue;
                dist[nx][ny] = dist[x][y] + 1;
                Q.push({nx, ny});
            }            
        }
    }
    return 0;
}