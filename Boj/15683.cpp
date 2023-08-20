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

const int PRECISION = 0;

using p = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = int(2e9);
int n,m,camers;
vvi board(9, vi(9));
vvi vist(9, vi(9));
vector<p> cams;

bool Bound(int x, int y){ return x < 0 or x >= n or y < 0 or y >= m; }

void Input(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
        cin >> board[i][j];
        if(board[i][j] and board[i][j] != 6){
            camers++;
            cams.push_back({i, j});
        }
        if(board[i][j] == 6) vist[i][j] = 1;
    }
}

void Paint(vvi& vist, int x, int y, int dir){
    vist[x][y] = 1;
    auto nx = x,ny = y;
    while(1){
        nx += dx[dir], ny += dy[dir];
        if(Bound(nx, ny) or board[nx][ny] == 6) break;
        vist[nx][ny] = 1;
    }
}

void Sol(){
    // all permutation
    int mn = INF;
    const int sz = pow(4, camers);
    for(int i = 0; i < sz; i++){
        int brute = i,cnt = 0;
        for(int x = 0; x < 9; x++) fill(vist[x].begin(), vist[x].end(), 0);
        vector<int> dirs(camers);
        for(int j = 0; j < camers; j++){
            dirs[j] = (brute % 4);
            brute /= 4;
        }   
        for(int j = 0; j < camers; j++){
            int X = cams[j].first, Y = cams[j].second;
            int T = board[X][Y];
            if(T == 1) Paint(vist, X, Y, dirs[j]);
            else if(T == 2){
                for(int d = 0; d <= 2; d += 2) Paint(vist, X, Y, (dirs[j] + d) % 4);
            }
            else if(T == 3){
                for(int d = 0; d < 2; d++) Paint(vist, X, Y, (dirs[j] + d) % 4);
            }
            else if(T == 4){
                for(int d = 0; d < 3; d++) Paint(vist, X, Y, (dirs[j] + d) % 4);
            }
            else if(T == 5){
                for(int d = 0; d < 4; d++) Paint(vist, X, Y, d);
            }
        }
        for(int x = 0; x < n; x++) for(int y = 0; y < m; y++){
            if(!vist[x][y] and board[x][y] != 6) cnt++;
        }
        mn = min<int>(mn, cnt);
    }
    cout << mn << "\n";
}


int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Input();
    Sol();
    return 0;
}