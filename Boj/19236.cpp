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
using vi = vector<int>;
using vvi = vector<vi>;

// d = (d + 1) % 8

constexpr int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
constexpr int dy[8] = { 0, -1, -1, -1, 0, 1, 1 ,1 };

bool OOB(int x,int y){ return x < 0 || x >= 4 || y < 0 || y >= 4; }

// board와 물고기의 이동 구현
struct Map{
    int v[4][4],d[4][4];
    void Move(int sx, int sy){
        pii cod[17]; 
        for(int i = 0; i < 17; i++) cod[i] = {-1, -1};
        for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++){
            cod[v[i][j]] = {i, j};
        }
        for(int k = 1; k <= 16; k++){
            if(cod[k].first != -1 and cod[k].second != -1){
                auto [x, y] = cod[k];
                auto dir = d[x][y], cur = v[x][y];
                for(int i = 0; i < 8; i++){
                    auto nx = x + dx[d[x][y]], ny = y + dy[d[x][y]];
                    if(OOB(nx, ny) || (nx == sx and ny == sy)) d[x][y] = (d[x][y] + 1) % 8;
                    else{
                        // swap 
                        swap(cod[v[nx][ny]], cod[v[x][y]]);
                        swap(d[nx][ny], d[x][y]);
                        swap(v[nx][ny], v[x][y]);
                        break;
                    }
                }
            }
        }
    }
} M;

// 상어의 이동구현

int DFS(Map B, int x, int y){
    int ret = B.v[x][y],mx = 0, dir = B.d[x][y];
    B.v[x][y] = B.d[x][y] = 0; B.Move(x, y);
    for(int i = 1; ; i++){
        auto nx = x + dx[dir] * i, ny = y + dy[dir] * i;
        if(OOB(nx, ny)) break;
        if(B.v[nx][ny]) mx = max<int>(mx, DFS(B, nx, ny));
    }
    return ret + mx;
}

int32_t main(){
    fastio;
    for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++){
        cin >> M.v[i][j] >> M.d[i][j]; M.d[i][j]--;
    }
    cout << DFS(M, 0, 0) << "\n";
    return 0;
}