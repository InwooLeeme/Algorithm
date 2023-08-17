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



void Main(){
    #define sz(v) v.size()
    using p = pair<int, int>;
    using vi = vector<int>; 
    using vvi = vector<vi>;
    // input
    int n,l,r,ret = 0; cin >> n >> l >> r;
    vvi board(n, vi(n)); for(auto& i : board) for(auto& j : i) cin >> j;
    auto Bound = [&](int x, int y){ return x < 0 or x >= n or y < 0 or y >= n; };
    auto Diff = [&](int v) ->bool { return (l <= v and v <= r); };
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0, -1};
    auto Print = [&]() -> void{
        for(auto& i : board){
            for(auto& j : i) cout << j << " ";
            cout << "\n";
        }
    };
    while(1){
        // set Group
        queue<p> Q; int components = 0; vvi dist(n, vi(n, -1));
        vi people;
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
            if(dist[i][j] != -1) continue;
            Q.push({i, j});
            dist[i][j] = components++;
            int sum = board[i][j],cnt = 1;
            while(Q.size()){
                auto [x, y] = Q.front(); Q.pop();
                for(int d = 0; d < 4; d++){
                    auto nx = x + dx[d], ny = y + dy[d];
                    if(Bound(nx, ny) or !Diff(abs(board[nx][ny] - board[x][y])) or dist[nx][ny] != -1) continue;
                    dist[nx][ny] = dist[i][j];
                    Q.push({nx, ny});
                    sum += board[nx][ny];
                    cnt++;
                }
            }
            people.push_back(sum / cnt);
        }
        if(components == n * n) break;
        // Move
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) board[i][j] = people[dist[i][j]];
        ret++;
    }
    cout << ret << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}