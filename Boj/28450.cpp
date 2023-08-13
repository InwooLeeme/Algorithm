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
using tii = tuple<int, int, int>;

const int PRECISION = 0;

int n,m,r;
int v[1111][1111];
constexpr int INF = int(2e18);
vector<vector<int>> D(1111, vector<int>(1111, INF));
bool Bound(int x, int y){ return x < 0 or x >= n or y < 0 or y >= m;}
const int dx[2] = {1, 0};
const int dy[2] = {0, 1};

int f(int x, int y){
    if(x == n - 1 and y == m - 1) return v[x][y];
    int& ret = D[x][y];
    if(ret != INF) return ret;
    ret = INF;
    for(int d = 0; d < 2; d++){
        auto nx = x + dx[d], ny = y + dy[d];
        if(Bound(nx, ny)) continue;
        ret = min<int>(ret, f(nx, ny) + v[x][y]);
    }
    return ret;
}

void Main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> v[i][j]; cin >> r;
    int ret = f(0, 0);
    if(ret > r) cout << "NO" << "\n";
    else cout << "YES\n" << ret << "\n";
}   

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}