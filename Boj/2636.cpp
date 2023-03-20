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

using pt = pair<int, int>;

int n,m;
int board[111][111],check[111][111];
vector<int> ret;
constexpr int dx[4] = {-1, 1, 0, 0};
constexpr int dy[4] = {0, 0, 1, -1};
bool Bound(int x,int y) { return x < 0 || x >= n || y < 0 || y >= m; }

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
        if(cnt) Q.push({x, y});
    }
    while(!Q.empty()){
        auto [x, y] = Q.front(); Q.pop();
        board[x][y] = 0;
    }
}

void DFS(vector<vector<int>>& vist, int x, int y, int idx){
    vist[x][y] = idx;
    for(int d = 0; d < 4; d++){
        auto nx = x + dx[d],ny = y + dy[d];
        if(Bound(nx, ny) || board[nx][ny] || vist[nx][ny]) continue;
        DFS(vist, nx, ny, idx);
    }
}

void FindInsideCheese(){
    memset(check, 0, sizeof check);
    vector<vector<int>> vist(n + 1, vector<int>(m + 1, 0));
    int cnt = 0;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
        if(board[i][j] || vist[i][j]) continue;
        DFS(vist, i, j, cnt + 1);
        cnt++;
    }
    if(cnt <= 1) return;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(vist[i][j] >= 2) check[i][j] = 1;
}

int CountChesse(){
    int ret = 0;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) ret += board[i][j];
    return ret;
}

bool CheckEmpty(){
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(board[i][j]) return 0;
    return 1;
}

int32_t main(){
    fastio;
    cin >> n >> m;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> board[i][j];
    int cnt = 0;
    while(1){
        ret.push_back(CountChesse());
        if(CheckEmpty()) break;
        FindInsideCheese();
        FindCheese();
        cnt++;
    }
    cout << cnt << "\n" << ret[cnt - 1] << "\n";
    return 0;
}