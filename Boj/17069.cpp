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

int n;
bool Bound(int x, int y){ return x <= 0 or x > n or y <= 0 or y > n; }
int board[35][35];
int d[35][35][3];
const int dx[3] = {1, 0, 1};
const int dy[3] = {0, 1, 1};

int Sol(int x, int y, int dir){
    if(x == n and y == n) return 1;
    int& ret = d[x][y][dir];
    if(ret != -1) return ret;
    ret = 0;
    for(int d = 0; d < 3; d++){
        auto nx = x + dx[d], ny = y + dy[d];
        if(dir == 1 and d == 0) continue;
        if(dir == 0 and d == 1) continue;
        if(Bound(nx, ny) or board[nx][ny]) continue;
        if(d == 2 and (board[x + 1][y] or board[x][y + 1])) continue;
        ret += Sol(nx, ny, d);
    }
    return ret;
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    memset(d, -1, sizeof d);
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) cin >> board[i][j];
    cout << Sol(1, 2, 1) << "\n";
    return 0;
}