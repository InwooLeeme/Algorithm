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

int n,m,sr,sc,er,ec, v[1111][1111];
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
auto bound = [](int x, int y){ return x < 0 or x >= n or y < 0 or y >= m; };
using pii = pair<int, int>;
using ti3 = tuple<int, int, int>;

void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> v[i][j];
    cin >> sr >> sc >> er >> ec; --sr,--sc,--er,--ec;
    vector<vector<int>> dist(n + 1, vector<int>(m + 1, (1 << 30)));
    vector<vector<int>> DS(n + 1, vector<int>(m + 1)), DE(n + 1, vector<int>(m + 1));
    queue<pii> q;
    DS[sr][sc] = 1; q.push({sr, sc});
    while(q.size()){
        auto [x, y] = q.front(); q.pop();
        for(int d = 0; d < 4; d++){
            auto nx = x + dx[d], ny = y + dy[d];
            if(bound(nx, ny) or DS[nx][ny] or !v[nx][ny]) continue;
            DS[nx][ny] = 1; q.push({nx, ny});
        }
    }
    DE[er][ec] = 1; q.push({er, ec});
    while(q.size()){
        auto [x, y] = q.front(); q.pop();
        for(int d = 0; d < 4; d++){
            auto nx = x + dx[d], ny = y + dy[d];
            if(bound(nx, ny) or DE[nx][ny] or !v[nx][ny]) continue;
            DE[nx][ny] = 1; q.push({nx, ny});
        }
    }
    if(DS[er][ec]){
        cout << 0 << "\n";
        return;
    }
    priority_queue<ti3, vector<ti3>, greater<>> pq;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
        if(v[i][j] and DE[i][j]){
            dist[i][j] = 0; pq.push({dist[i][j], i, j});
        }
    }
    while(pq.size()){
        auto [cdist, x, y] = pq.top(); pq.pop();
        if(dist[x][y] != cdist) continue;
        for(int d = 0; d < 4; d++){
            auto nx = x + dx[d], ny = y + dy[d];
            if(bound(nx, ny)) continue;
            if(dist[nx][ny] > cdist + 1){
                pq.push({dist[nx][ny] = cdist + 1, nx, ny});
            }
        }
    }
    int res = 1 << 30;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
        if(DS[i][j]){
            res = min<int>(res, dist[i][j]);
        }
    }
    cout << res << "\n";
}

void Main(){
    int t = 1; 
//ri(t);
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
