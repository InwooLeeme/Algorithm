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

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n,m; cin >> n >> m;
    auto Bound = [&](int x, int y) -> bool {return x < 0 or x >= n or y < 0 or y >= m; };
    vector<vector<int>> board(n + 1, vector<int>(m + 1));
    vector<pt> v;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
        cin >> board[i][j];
        if(board[i][j]) v.push_back({i, j});
    }
    int mx = 0,curd = 0;
    for(auto& [stx, sty] : v){
        vector<vector<int>> dist(n + 1, vector<int>(m + 1, -1));
        queue<pt> Q;
        Q.push({stx, sty});
        dist[stx][sty] = 0;
        while(Q.size()){
            auto [x, y] = Q.front(); Q.pop();
            for(int d = 0; d < 4; d++){
                auto nx = x + dx[d], ny = y + dy[d];
                if(Bound(nx, ny) or dist[nx][ny] != -1 or !board[nx][ny]) continue;
                dist[nx][ny] = dist[x][y] + 1;
                Q.push({nx, ny});
            }
        }
        for(auto& [enx, eny] : v){
            if(dist[enx][eny] == -1) continue;
            if(curd < dist[enx][eny]){
                curd = dist[enx][eny];
                mx = board[stx][sty] + board[enx][eny];
            }
            else if(curd == dist[enx][eny] and mx < board[stx][sty] + board[enx][eny]) mx = board[stx][sty] + board[enx][eny];
        }
    }
    cout << mx << "\n";
    return 0;
}