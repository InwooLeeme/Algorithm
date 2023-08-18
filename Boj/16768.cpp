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
    using p = pair<int, int>;
    using vi = vector<int>; using vvi = vector<vi>;
    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0 ,1 ,0, -1};
    int n,k,m = 10; cin >> n >> k;
    vector<string> v(n); for(auto& i : v) cin >> i;
    auto Bound = [&](int x, int y) -> bool{ return x < 0 or x >= n or y < 0 or y >= m; };
    while(1){
        bool check = 0;
        vvi vist(n, vi(m));
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
            if(vist[i][j] or v[i][j] == '0') continue;
            vist[i][j] = 1; int cnt = 1;
            queue<p> Q, Q2; Q.push({i, j}); Q2.push({i, j});
            while(!Q.empty()){
                auto [x, y] = Q.front(); Q.pop();
                for(int d = 0; d < 4; d++){
                    auto nx = x + dx[d], ny = y + dy[d];
                    if(Bound(nx, ny) or vist[nx][ny] or v[nx][ny] != v[i][j]) continue;
                    vist[nx][ny] = 1;
                    Q.push({nx, ny});
                    Q2.push({nx, ny});
                    cnt++;
                }
            }
            if(cnt < k) continue;
            check = 1;
            while(!Q2.empty()){
                auto [x, y] = Q2.front(); Q2.pop();
                v[x][y] = '0';
            }
        }
        if(!check) break;
        // Gravity
        for(int j = 0; j < m; j++) for(int i = n - 1; i > 0; i--){
            int temp = i - 1;
            while(v[i][j] == '0' and temp >= 0) swap(v[i][j], v[temp--][j]);
        }
    }
    for(auto& i : v) cout << i << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}