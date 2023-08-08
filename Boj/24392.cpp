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
const int MOD = int(1e9) + 7;

int d[1111][1111];
int v[1111][1111];
const int dx[3] = {-1, -1, -1};
const int dy[3] = {-1, 0, 1};
int n,m;
bool Bound(int x, int y){ return x < 0 or x >= n or y < 0 or y >= m; }

int F(int x, int y){
    if(!x) return 1;
    int& ret = d[x][y];
    if(ret != -1) return ret;
    ret = 0;
    for(int d = 0; d < 3; d++){
        auto nx = x + dx[d], ny = y + dy[d];
        if(Bound(nx, ny) or !v[nx][ny]) continue;
        ret += F(nx, ny) % MOD;
    }
    return ret;
}

void Main(){
    memset(d, -1, sizeof d);
    cin >> n >> m;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> v[i][j];
    int ret = 0;
    for(int i = 0; i < m; i++) if(v[n - 1][i]) ret += F(n - 1, i) % MOD;
    cout << ret % MOD << "\n";
}   

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}