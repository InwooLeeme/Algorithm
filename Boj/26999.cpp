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
vector<string> board;
vector<vector<bool>> vist;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
const int ddx[8] = {0, 0, 1, 1, 1, -1, -1, -1}, ddy[8] = {1, -1, 1, 0, -1, 1, 0, -1};

int DFS(int x,int y){
    int ret = 1;
    vist[x][y] = 1;
    for(int i = 0; i < 4; i++){
        auto nx = x + dx[i],ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(vist[nx][ny] || board[nx][ny] == '.') continue;
        ret += DFS(nx, ny);        
    }
    return ret;
}

int32_t main(){
    fastio;
    cin >> m >> n; cin.ignore();
    int mx = 0;
    vist.resize(n);
    board.resize(n);
    for(int i = 0; i < n; i++) vist[i].resize(m);
    for(int i = 0; i < n; i++) cin >> board[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vist[i][j] and board[i][j] == '*'){
                mx = max<int>(mx, DFS(i, j));
            }
        }
    }
    cout << mx << "\n";
    return 0;
}