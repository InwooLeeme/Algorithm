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

int n,m;
bool Bound(int x, int y) { return x < 0 or x >= n or y < 0 or y >= m; }
int board[111][111];
int D[111][111];
const int dx[3] = {-1, 0, 1};
const int dy[3] = {1, 1, 1};

int f(int x, int y){
    if(x == n - 1 and y == m - 1) return board[x][y];
    int& ret = D[x][y];
    if(ret != -1) return ret;
    ret = -int(2e9);
    for(int d = 0; d < 3; d++){
        auto nx = x + dx[d], ny = y + dy[d];
        if(Bound(nx, ny)) continue;
        ret = max<int>(ret, f(nx, ny) + board[x][y]);
    }
    return ret;
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> board[i][j];
    memset(D, -1, sizeof D);
    cout << f(0, 0) << '\n';
    return 0;
}