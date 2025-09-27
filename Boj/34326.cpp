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

using pii = pair<int, int>;
int n,m;
string v[1111];
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

auto sol = [](){
    auto bound = [](int x, int y){ return x < 0 or x >= n or y < 0 or y >= m; };
    auto move = [](int x, int y, int d)-> pii{ return {x + dx[d], y + dy[d]}; };
    int t1 = 0,t2 = 0,x1 = -1, y1 = -1,d1 = 0,x2 = -1, y2 = -1, d2 = 0;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
        if(v[i][j] == 'S'){
            x1 = i, y1 = j; x2 = i, y2 = j;
            break;
        }
    }
    for(int d = 0; d < 4; d++){
        auto [nx, ny] = move(x1, y1, d);
        if(!bound(nx, ny) and v[nx][ny] == '.'){
            d1 = d2 = d; break;
        }
    }
    while(v[x1][y1] != 'E'){
        d1 = (d1 + 1) % 4;
        while(1){
            auto [nx, ny] = move(x1, y1, d1);
            if(!bound(nx, ny) and v[nx][ny] != '*') break;
            d1 = (d1 - 1 + 4) % 4;
        }
        auto [nx, ny] = move(x1, y1, d1);
        x1 = nx, y1 = ny;
        t1++;
    }
    while(v[x2][y2] != 'E'){
        d2 = (d2 - 1 + 4) % 4;
        while(1){
            auto [nx, ny] = move(x2, y2, d2);
            if(!bound(nx, ny) and v[nx][ny] != '*') break;
            d2 = (d2 + 1) % 4;
        }
        auto [nx, ny] = move(x2, y2, d2);
        x2 = nx, y2 = ny;
        t2++;
    }
    return (t1 == t2 ? "SAME" : ((t1 < t2) ? "LEFT IS BEST" : "RIGHT IS BEST"));
};

void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << sol() << "\n";
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
