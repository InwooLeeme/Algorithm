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

#define sz(v) (v).size()

using p = pair<int, int>;

const int PRECISION = 0;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int n,m;
int board[22][22];
int dist[22][22];

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    cin >> n >> m;
    vector<p> v;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
        cin >> board[i][j];
        if(!board[i][j]) v.push_back({i, j});
    }
    auto Bound = [&](int x, int y) -> bool{return x < 0 or x >= n or y < 0 or y >= m; };
    int mx = 0;
    vector<int> chk; for(int i = 0; i < sz(v); i++) chk.push_back(i < 2 ? 0 : 1);
    do{
        int ret = 0;
        memset(dist, -1, sizeof dist);
        p t1 = {-1, -1},t2;
        for(int i = 0; i < sz(chk); i++){
            if(!chk[i]){
                if(t1.first == -1) t1 = v[i];
                else t2 = v[i];
            }
        }
        board[t1.first][t1.second] = board[t2.first][t2.second] = 1;
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
            if(!board[i][j] or board[i][j] == 1 or dist[i][j] != -1) continue;
            int sum = 0;
            bool flag = 0;
            queue<p> Q,Q2;
            Q.push({i, j}); Q2.push({i, j}); dist[i][j] = 0;
            while(Q.size()){
                auto [x, y] = Q.front(); Q.pop();
                for(int d = 0; d < 4; d++){
                    auto nx = x + dx[d], ny = y + dy[d];
                    if(Bound(nx, ny) or dist[nx][ny] != -1 or board[nx][ny] == 1) continue;
                    if(!board[nx][ny]){ flag = 1; }
                    dist[nx][ny] = dist[x][y] + 1;
                    Q.push({nx, ny});
                    Q2.push({nx, ny});
                }
            }
            if(flag) continue;
            ret += sz(Q2);
        }
        mx = max<int>(mx, ret);
        board[t1.first][t1.second] = board[t2.first][t2.second] = 0;
    }while(next_permutation(chk.begin(), chk.end()));
    cout << mx << "\n";
    return 0;
}