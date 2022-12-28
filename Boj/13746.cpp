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

int n,m;
string board[55];
bool vist[55][55];

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
const int ddx[8] = {0, 0, 1, 1, 1, -1, -1, -1}, ddy[8] = {1, -1, 1, 0, -1, 1, 0, -1};

bool OOB(int x,int y){return x < 0 || x >= n || y < 0 || y >= m; }

void DFS(int x,int y){
    vist[x][y] = 1;
    for(int dir = 0; dir < 4; dir++){
        auto nx = x + dx[dir],ny = y + dy[dir];
        if(OOB(nx, ny) || vist[nx][ny] || board[nx][ny] == 'W') continue;
        DFS(nx, ny);
    }
}

int32_t main(){
    fastio;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> board[i];
    int mn = int(1e9),t1 = 0,t2 = 0, t3 = 0;
    for(int i = 0; i <  n; i++){
        for(int j = 0; j < m; j++){
            if(!vist[i][j] and board[i][j] == 'L'){
                DFS(i, j);
                t1++;
            }
        }
    }
    mn = min<int>(mn, t1);
    cout << mn << "\n";
    return 0;
}