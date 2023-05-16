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
string board[55];
int vist[55][55];
bool check = 0;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

bool Bound(int x, int y) { return x < 0 or x >= n or y < 0 or y >= m; }

void f(int x, int y, char cur, int px, int py){
    vist[x][y] = 1;
    for(int d = 0; d < 4; d++){
        auto nx = x + dx[d], ny = y + dy[d];
        if(Bound(nx, ny) or board[nx][ny] != cur) continue;
        if(nx == px and ny == py) continue;
        if(vist[nx][ny]){
            check = 1;
            return;
        }
        f(nx, ny, cur, x, y);
    }
    vist[x][y] = 0;
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> board[i];
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
        if(!vist[i][j]){
            f(i, j, board[i][j], -1, -1);
            if(check){
                cout << "Yes" << "\n";
                return 0;
            }
        }
    }
    cout << "No" << "\n";
    return 0;
}