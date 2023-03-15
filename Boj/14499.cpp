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

int n,m,x,y,order;
int board[22][22];
int v[7];
vector<int> cmd;

bool Bound(int x,int y) { return x < 0 || x >= n || y < 0 || y >= m; }
// 동
void R(){
    int temp = v[6];
    v[6] = v[3];
    v[3] = v[1];
    v[1] = v[4];
    v[4] = temp;
}
// 서
void L(){
    int temp = v[4];
    v[4] = v[1];
    v[1] = v[3];
    v[3] = v[6];
    v[6] = temp;
}
// 북
void N(){
    int temp = v[6];
    v[6] = v[5];
    v[5] = v[1];
    v[1] = v[2];
    v[2] = temp;
}
// 남
void D(){
    int temp = v[5];
    v[5] = v[6];
    v[6] = v[2];
    v[2] = v[1];
    v[1] = temp;
}

int32_t main(){
    fastio;
    // Input
    cin >> n >> m >> x >> y >> order;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> board[i][j];
    cmd.resize(order);
    for(auto& i : cmd) cin >> i;
    for(const auto& i : cmd){
        if(i == 1){ // 동
            if(Bound(x, y + 1)) continue;
            R();
            y = y + 1;
            if(!board[x][y]) board[x][y] = v[6];
            else v[6] = board[x][y], board[x][y] = 0;
        }
        else if(i == 2){ // 서
            if(Bound(x, y - 1)) continue;
            L();
            y = y - 1;
            if(!board[x][y]) board[x][y] = v[6];
            else v[6] = board[x][y], board[x][y] = 0;
        }
        else if(i == 3){ // 북
            if(Bound(x - 1, y)) continue;
            N();
            x = x - 1;
            if(!board[x][y]) board[x][y] = v[6];
            else v[6] = board[x][y], board[x][y] = 0;
        }
        else if(i == 4){ // 남
            if(Bound(x + 1, y)) continue;
            D();
            x = x + 1;
            if(!board[x][y]) board[x][y] = v[6];
            else v[6] = board[x][y], board[x][y] = 0;
        }
        cout << v[1] << "\n";
    }
    return 0;
}