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

using tii = tuple<int, int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;

const int PRECISION = 0;
const int dx[6] = {1, -1, 0, 0, 0, 0};
const int dy[6] = {0, 0, 1, -1, 0, 0};
const int dz[6] = {0, 0, 0, 0, -1, 1};
const int n = 5;
const int INF = int(2e9);

vvvi board1(n, vvi(n, vi(n))), board2(n, vvi(n, vi(n)));

bool Bound(int x, int y, int z){ return x < 0 or x >= n or y < 0 or y >= n or z < 0 or z >= n;}

int BFS(){
    if(!board2[0][0][0] or !board2[4][4][4]) return INF;
    vvvi dist(n, vvi(n, vi(n, -1)));
    queue<tii> Q;
    dist[0][0][0] = 0;
    Q.push({0, 0, 0});
    while(Q.size()){
        auto [x, y, z] = Q.front(); Q.pop();
        if(x == 4 and y == 4 and z == 4) break;
        for(int d = 0; d < 6; d++){
            auto nx = x + dx[d], ny = y + dy[d], nz = z + dz[d];
            if(Bound(nx, ny, nz) or !board2[nx][ny][nz] or dist[nx][ny][nz] != -1) continue;
            dist[nx][ny][nz] = dist[x][y][z] + 1;
            Q.push({nx, ny, nz});
        }
    }
    return (dist[4][4][4] == -1 ? INF : dist[4][4][4]);
}
/* Rotate 90 degree 2D Array */
void Rotate(int k){
    int temp[5][5];
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) temp[i][j] = board1[4 - j][i][k];
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) board1[i][j][k] = temp[i][j];
}

int Sol(){
    int mn = INF;
    vector<int> check(n); iota(check.begin(), check.end(), 0);
    // All Permutation
    const int sz = (1 << (2 * 5));
    do{
        for(int i = 0; i < sz; i++){
            int brute = i;
            vi rotates(n); // 몇번 회전할지 저장
            for(int j = 0; j < n; j++) rotates[j] = (brute % 4), brute /= 4;
            // Rotate Boards
            for(int k = 0; k < n; k++) for(int t = 0; t < rotates[k]; t++) Rotate(k);
            for(int k = 0; k < n; k++) for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) board2[i][j][check[k]] = board1[i][j][k];
            mn = min<int>(mn, BFS());
            for(int k = 0; k < n; k++) for(int t = 0; t < 4 - rotates[k]; t++) Rotate(k);
        } 
    }while(next_permutation(check.begin(), check.end()));
    return mn;
}

void Main(){
    // Input
    for(int k = 0; k < n; k++) for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> board1[i][j][k];
    int ret = Sol();
    cout << (ret == INF ? -1 : ret) << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}