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

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
const int ddx[8] = {0, 0, 1, 1, 1, -1, -1, -1}, ddy[8] = {1, -1, 1, 0, -1, 1, 0, -1};
constexpr int INF = int(1e9) + 7;

int n;
int board[111][111];

bool OOB(int x,int y){ return (x < 0 || x >= n || y < 0 || y >= n); }

void Indexing(){
    vector<vector<bool>> vist(111, vector<bool>(111, 0));
    queue<pii> Q;
    int idx = 0;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
        if(board[i][j] and !vist[i][j]){
            Q.push({i, j});
            vist[i][j] = 1;
            board[i][j] = ++idx;
            while(!Q.empty()){
                auto [curX, curY] = Q.front(); Q.pop();
                for(int dir = 0; dir < 4; dir++){
                    auto nx = curX + dx[dir],ny = curY + dy[dir];
                    if(OOB(nx, ny) || !board[nx][ny] || vist[nx][ny]) continue;
                    board[nx][ny] = idx;
                    Q.push({nx, ny});
                    vist[nx][ny] = 1;
                }
            }
        }
    }
}

int Sol(int x,int y){
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, -1));
    queue<pii> Q;
    dist[x][y] = 0;
    Q.push({x, y});
    while(!Q.empty()){
        auto [curX, curY] = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){
            auto nx = curX + dx[dir],ny = curY + dy[dir];
            if(OOB(nx, ny) || dist[nx][ny] != -1 || board[nx][ny] == board[x][y]) continue;
            if(board[nx][ny]) return dist[curX][curY]; // 다른 섬을 만난 경우
            dist[nx][ny] = dist[curX][curY] + 1;
            Q.push({nx, ny});
        }
    }
    return INF;
}

int32_t main(){
    fastio;
    cin >> n;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> board[i][j];
    // Indexing
    Indexing();
    int ret = INF;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            bool flag = 1;
            if(board[i][j]){ // 가장 자리 판별
                for(int dir = 0; dir < 4; dir++){
                    auto nx = i + dx[dir],ny = j + dy[dir];
                    if(OOB(nx, ny) || board[nx][ny]) continue;
                    flag = 0;
                }
            }
            if(flag) continue;
            ret = min<int>(ret, Sol(i, j));
        }
    }
    cout << ret << "\n";
    return 0;
}