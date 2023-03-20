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

int n,m;
int board[111][111];
int check[111][111];
bool Bound(int x,int y) { return x < 0 || x >= n || y < 0 || y >= m; }
constexpr int dx[4] = {-1, 0, 1, 0};
constexpr int dy[4] = {0, 1, 0, -1};

bool CheckEmpty(){
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(board[i][j]) return 0;
    return 1;
}

void FindCheese(){
    queue<pt> Q;
    for(int x = 0; x < n; x++) for(int y = 0; y < m; y++){
        if(!board[x][y]) continue;
        int cnt = 0;
        for(int d = 0; d < 4; d++){
            auto nx = x + dx[d],ny = y + dy[d];
            if(Bound(nx, ny) || board[nx][ny] || (!board[nx][ny] and check[nx][ny])) continue;
            cnt++;
        }
        if(cnt >= 2) Q.push({x, y});
    }
    // remove cheese
    while(!Q.empty()){
        auto [x, y] = Q.front(); Q.pop();
        board[x][y] = 0;
    }
}

void PR(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << board[i][j] << ' ';
        }
        cout << "\n";
    }
}

void DFS(vector<vector<int>>& vist, int x, int y, int com){
    vist[x][y] = com;
    for(int d = 0; d < 4; d++){
        auto nx = x + dx[d],ny = y + dy[d];
        if(Bound(nx, ny) || vist[nx][ny] || board[nx][ny] == 1) continue;
        DFS(vist, nx, ny, com);
    }
}

void FindAirInsideCheese(){
    memset(check, 0, sizeof check);
    vector<vector<int>> vist(n + 1, vector<int>(m + 1));
    int components = 1;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(!board[i][j] and !vist[i][j]){
        DFS(vist, i, j, components);
        components++;
    }
    if(components >= 2){
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(vist[i][j] >= 2) check[i][j] = 1;
    }
}

int32_t main(){
    fastio;
    // Input
    cin >> n >> m;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> board[i][j];
    // Sol
    int ret = 0;
    while(1){
        if(CheckEmpty()) break;
        FindAirInsideCheese();
        FindCheese();
        ret++;
    }
    cout << ret << "\n";
    return 0;
}