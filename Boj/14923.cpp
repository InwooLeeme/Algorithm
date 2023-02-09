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

using pii = pair<int, int>;
using tii = tuple<int, int, int>;

const int dx[] = {0, 1, 0, -1},dy[] = {1, 0, -1, 0};
int board[1111][1111];
int dist[1111][1111][2];
int n,m;
pii st,en;

int32_t main(){
    fastio;
    memset(dist, -1, sizeof dist);
    cin >> n >> m >> st.first >> st.second >> en.first >> en.second; --st.first,--st.second,--en.first,--en.second;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> board[i][j];
    queue<tii> Q;
    dist[st.first][st.second][0] = 0;
    Q.push({st.first, st.second, 0});
    // BFS
    while(!Q.empty()){
        auto [x, y, t] = Q.front(); Q.pop();
        for(int d = 0; d < 4; d++){
            auto nx = x + dx[d],ny = y + dy[d];
            auto nt = t;
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist[nx][ny][nt] != -1) continue;
            if(!board[nx][ny]){
                dist[nx][ny][nt] = dist[x][y][t] + 1;
                Q.push({nx, ny, nt});
            }
            else if(board[nx][ny] and !nt){
                dist[nx][ny][1] = dist[x][y][t] + 1;
                Q.push({nx, ny, 1});
            }
            else if(board[nx][ny] and nt){
                continue;
            }
        }
    }
    if(dist[en.first][en.second][0] == -1 and dist[en.first][en.second][1] != -1) cout << dist[en.first][en.second][1] << "\n";
    else if(dist[en.first][en.second][0] != -1 and dist[en.first][en.second][1] == -1) cout << dist[en.first][en.second][0] << "\n";
    else cout << min<int>(dist[en.first][en.second][0], dist[en.first][en.second][1]) << "\n";
    return 0;
}