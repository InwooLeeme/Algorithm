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

using p = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

const int PRECISION = 0;

int n,m,k,d,b;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

void Sol(){
    int ret = 0;
    --b;
    vector<p> bomb(k); for(auto& [x, y] : bomb) cin >> x >> y,--x,--y;
    vvi dist(n + 1, vi(m + 1, -1));
    vvi board(n + 1, vi(m + 1));
    for(auto& [x, y] : bomb) board[x][y] = 1;
    auto Bound = [](int x, int y) -> bool{ return x < 0 or x >= n or y < 0 or y >= m; };
    queue<p> Q; Q.push(bomb[b]); dist[bomb[b].first][bomb[b].second] = 0;
    while(Q.size()){
        auto [x, y] = Q.front(); Q.pop();
        ret++;
        for(int i = 0; i < 4; i++){
            for(int f = 0; f <= d; f++){
                auto nx = x + dx[i] * f, ny = y + dy[i] * f;
                if(Bound(nx, ny) or dist[nx][ny] != -1 or !board[nx][ny]) continue;
                if(board[nx][ny]) dist[nx][ny] = dist[x][y] + 1, Q.push({nx, ny});
            }
        }
    }
    cout << ret << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    while(cin >> n >> m >> k >> d >> b and n) Sol();
    return 0;
}