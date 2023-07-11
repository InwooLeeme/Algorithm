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

using vi = vector<int>;
using vvi = vector<vi>;
using pt = pair<int, int>;

int board[6][6];
bool Bound(int x, int y){ return x < 0 or x >= 5 or y < 0 or y >= 5; }
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<int> v = {1, 2, 3, 4, 5, 6};
    int r,c;
    unordered_map<int, pt> M;
    for(int i = 0; i < 5; i++) for(int j = 0; j < 5; j++){
        cin >> board[i][j];
        if(1 <= board[i][j] and board[i][j] <= 6) M[board[i][j]] = {i, j};
    }
    cin >> r >> c;
    int mn = int(2e9);
    auto BFS = [&](pt& x) -> vvi{
        queue<pt> Q;
        vvi dist(6, vi(6, -1));
        Q.push(x);
        dist[x.first][x.second] = 0;
        while(Q.size()){
            auto [curx, cury] = Q.front(); Q.pop();
            for(int d = 0; d < 4; d++){
                auto nx = curx + dx[d], ny = cury + dy[d];
                if(Bound(nx, ny) or board[nx][ny] == -1 or dist[nx][ny] != -1) continue;
                dist[nx][ny] = dist[curx][cury] + 1;
                Q.push({nx, ny});
            }
        }
        return dist;
    };
    do{
        bool flag = 0;
        pt prv = {r, c};
        int ret = 0;
        for(auto& I : v){
            auto& [nx, ny] = M[I];
            auto dist = BFS(prv);
            if(dist[nx][ny] == -1){
                flag = 1;
                break;
            }
            ret += dist[nx][ny];
            prv = {nx, ny};
        }        
        if(flag) continue;
        mn = min<int>(mn, ret);
    }while(next_permutation(v.begin(), v.end()));
    if(mn == int(2e9)) cout << -1 << "\n";
    else cout << mn << "\n";
    return 0;
}