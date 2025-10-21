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

using pii = pair<int, int>;
using ti3 = tuple<int, int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

const int PRECISION = 0;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
constexpr int INF = int(2e18);
constexpr int NINF = -INF;


void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m)), dist(n, vector<int>(m, INF));
    auto bound = [&](int x, int y){ return x < 0 or x >= n or y < 0 or y >= m; };
    for(auto& i : v) for(auto& j : i){
        cin >> j;
        if(j == -2) j = 0;
    }
    priority_queue<ti3, vector<ti3>, greater<>> pq;
    for(int i = 1; i < n; i++){
        if(v[i][0] != -1){
            pq.push({dist[i][0] = v[i][0], i, 0});
        }
    }
    for(int i = 1; i < m; i++){
        if(v[n - 1][i] != -1){
            pq.push({dist[n - 1][i] = v[n - 1][i], n - 1, i});
        }
    }
    while(pq.size()){
        auto [cdist, x, y] = pq.top(); pq.pop();
        if(x == 0 or y == m - 1){
            cout << cdist << "\n";
            return;
        }
        for(int d = 0; d < 8; d++){
            auto nx = x + ddx[d], ny = y + ddy[d];
            if(bound(nx, ny)) continue;
            if(v[nx][ny] == -1) continue;
            if(dist[nx][ny] > cdist + v[nx][ny]){
                pq.push({dist[nx][ny] = cdist + v[nx][ny], nx, ny});
            }
        }
    }
    cout << -1 << "\n";
}

void Main(){
    int t = 1; 
    //cin >> t;
    while(t--) solve();
    /* for(int tc = 1; tc <= t; tc++){
    cout << "Case #" << tc << ": "; solve();
    } */
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}
