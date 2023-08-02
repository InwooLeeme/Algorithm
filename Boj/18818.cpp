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

using T = tuple<int,int,int>;

const int PRECISION = 0;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

int dist[111][111][4];

void Sol(){
    int n; cin >> n;
    vector<string> v(n); for(auto& i : v) cin >> i;
    queue<T> Q; Q.push({0, 0, 0}); 
    for(int i = 0; i < 4; i++) dist[0][0][i] = 1;
    auto Bound = [&](int x, int y) -> bool{ return x < 0 or x >= n or y < 0 or y >= n; };
    while(Q.size()){
        auto [x, y, d] = Q.front(); Q.pop();
        if(x == n - 1 and y == n - 1){
            cout << d << "\n";
            return;
        }
        for(int dir = 0; dir < 4; dir++){
            auto nx = x + dx[dir], ny = y + dy[dir];
            while(!Bound(nx, ny) and v[nx][ny] == '.' and !dist[nx][ny][dir]){
                dist[nx][ny][dir] = 1;
                Q.push({nx, ny, d + 1});
                nx += dx[dir], ny += dy[dir];
            }
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Sol();
    return 0;
}