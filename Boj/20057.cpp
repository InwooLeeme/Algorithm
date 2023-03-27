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

int n,ret;
int board[511][511];
bool Bound(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};
const int kdx[4][9] = {
    {-1, 1, -1, 1, -1, 1, -2, 2, 0},
    {0, 0, 1, 1, -1, -1, 0, 0, 2},
    {-1, 1, -1, 1, -1, 1, -2, 2, 0},
    {0, 0, -1, -1, 1, 1, 0, 0, -2},
};
const int kdy[4][9] = {
    {0, 0, -1, -1, 1, 1, 0, 0, -2},
    {-1, 1, -1, 1, -1, 1, 2, -2, 0},
    {0, 0, 1, 1, -1, -1, 0, 0, 2},
    {-1, 1, -1, 1, 1, -1, 2, -2, 0},
};
const int percent[9] = {7, 7, 10, 10, 1, 1, 2, 2, 5};

void MoveSand(int x, int y, int d){
    auto nx = x + dx[d], ny = y + dy[d]; // y
    int sand = board[nx][ny];
    int t = sand;
    if(!sand) return;
    for(int i = 0; i < 9; i++){
        auto nnx = nx + kdx[d][i];
        auto nny = ny + kdy[d][i];
        int p = (t * percent[i]) / 100;
        if(Bound(nnx, nny)) ret += p; 
        else board[nnx][nny] += p;
        sand -= p;
    }
    auto ax = nx + dx[d], ay = ny + dy[d]; // alpha
    if(Bound(ax, ay)) ret += sand;
    else board[ax][ay] += sand;
    board[nx][ny] = 0;
}

int32_t main(){
    fastio;
    cin >> n;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> board[i][j];
    // Move
    int d = 0,x = n >> 1, y = n >> 1,len = 1;
    while(1){
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < len; j++){
                MoveSand(x, y, d);
                x += dx[d], y += dy[d];
            }
            d = (d + 1) % 4;
        }
        len++;
        if(len == n){
            for(int j = 0; j < len; j++){
                MoveSand(x, y, d);
                x += dx[d], y += dy[d];
            }
            break;
        }
    }
    cout << ret << "\n";
    return 0;
}