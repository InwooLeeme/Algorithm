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

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 0x7f7f7f7f;

int n,m;
bool Bound(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }
int dep[333][333];
int board[333][333];

int32_t main(){
    fastio;
    cin >> m >> n;
    queue<pt> Q;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
        cin >> board[i][j];
        if(i == 0 || i == n - 1 || j == 0 || j == m - 1){
            dep[i][j] = board[i][j];
            Q.push({i, j});
        }
        else dep[i][j] = INF;
    }
    while(!Q.empty()){
        auto [x, y] = Q.front(); Q.pop();
        for(int d = 0; d < 4; d++){
            auto nx = x + dx[d], ny = y + dy[d];
            if(Bound(nx, ny)) continue;
            if(dep[nx][ny] > dep[x][y]){
                dep[nx][ny] = max<int>(dep[x][y], board[nx][ny]);
                Q.push({nx, ny});
            }
        }
    }
    int ret = 0;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) ret += (dep[i][j] - board[i][j]);
    cout << ret << "\n";
    return 0;
}