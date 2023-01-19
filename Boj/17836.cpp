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

int board[111][111];
int dist[111][111][2];
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0, 1, 0, -1};
int n,m,t;

bool OOB(int x,int y){return x < 1 || x > n || y < 1 || y > m; }

struct Info{
    int x,y,t;
};

int32_t main(){
    fastio;
    memset(dist, -1, sizeof dist);
    cin >> n >> m >> t;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) cin >> board[i][j];
    queue<Info> Q;
    dist[1][1][0] = 0;
    Q.push({1, 1, 0});
    int ret = 1e9;
    while(!Q.empty()){
        auto [curX, curY, t] = Q.front(); Q.pop();
        if(curX == n and curY == m) ret = min<int>(ret, dist[curX][curY][t]);
        if(board[curX][curY] == 2){
            t = 1;
            dist[curX][curY][1] = dist[curX][curY][0];
        }
        for(int dir = 0; dir < 4; dir++){
            auto nx = curX + dx[dir],ny = curY + dy[dir];
            auto nt = t;
            if(OOB(nx, ny)) continue;
            if(!nt){    
                if(board[nx][ny] == 1 || dist[nx][ny][nt] != -1) continue;
                dist[nx][ny][0] = dist[curX][curY][0] + 1;
                Q.push({nx, ny, 0});
            }
            else{
                if(dist[nx][ny][nt] != -1) continue;
                dist[nx][ny][1] = dist[curX][curY][1] + 1;
                Q.push({nx, ny, 1});
            }
        }
    }
    if(ret > t) cout << "Fail" << "\n";
    else cout << ret << "\n";
    return 0;
}