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

const int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1}, dy[8] = {1, -1, 1, 0, -1, 1, 0, -1};

void Main(){
    int t; cin >> t;
    for(int tc = 1; tc <= t; tc++){
        int n,ret = 0; cin >> n;
        vector<string> v(n); for(auto& i : v) cin >> i;
        vvi C(n + 1, vi(n + 1));
        auto Bound = [&](int x, int y) -> bool{ return x < 0 or x >= n or y < 0 or y >= n; };
        auto I = [&](int x, int y){
            for(int d = 0; d < 8; d++){
                auto nx = x + dx[d], ny = y + dy[d];
                if(Bound(nx, ny)) continue;
                if(v[nx][ny] == '*') return 1;
            }
            return 0;
        };
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
            if(I(i, j) or C[i][j] or v[i][j] == '*') continue;
            queue<p> Q;
            Q.push({i, j}); ret++; C[i][j] = 1;
            while(Q.size()){
                auto [x, y] = Q.front(); Q.pop();
                for(int d = 0; d < 8; d++){
                    auto nx = x + dx[d], ny = y + dy[d];
                    if(Bound(nx, ny)) continue;
                    if(v[nx][ny] == '*' or C[nx][ny]);
                    else if(I(nx, ny)) C[nx][ny] = 1;
                    else Q.push({nx, ny}), C[nx][ny] = 1;
                }
            }
        }
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
            if(v[i][j] == '*' or C[i][j]) continue;
            if(I(i, j)) ret++;
        }
        cout << "Case #" << tc << ": " << ret << "\n";
    }
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}