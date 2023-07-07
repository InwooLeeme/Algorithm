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

int n,m,k;
int d[111][111];
int board[111][111];
bool Bound(int x, int y){ return x < 0 or x >= n or y < 0 or y >= m; }
const int MOD = 1e9 + 7;

int DFS(int x, int y, int c){
    if(x == n - 1 and y == m - 1) return 1;
    int& ret = d[x][y];
    if(ret != -1) return ret;
    ret = 0;
    for(int nx = x + 1; nx < n; nx++){
        for(int ny = y + 1; ny < m; ny++){
            if(!Bound(nx, ny) and board[nx][ny] != c) ret = (ret + DFS(nx, ny, board[nx][ny])) % MOD;
        }
    }
    return ret;
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    memset(d, -1, sizeof d);
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> board[i][j];
    cout << DFS(0, 0, board[0][0]) % MOD << "\n";
    return 0;
}