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
constexpr int MOD = int(1e9) + 9;

void Sol(){
    int n,m; cin >> n >> m;
    vector<string> v(n); for(auto& i : v) cin >> i;
    vector<vector<int>> d(n +  1, vector<int>(m + 1, -1));
    auto Bound = [&](int x, int y) -> bool { return x < 0 or x >= n or y < 0 or y >= m; };
    auto F = [&](int x, int y, auto&& F) -> int{
        if(x == n - 1 and y == m - 1) return 1;
        int& ret = d[x][y];
        if(ret != -1) return ret;
        ret = 0;
        if(v[x][y] == 'E') ret += F(x, y + 1, F);
        if(v[x][y] == 'S') ret += F(x + 1, y, F);
        if(v[x][y] == 'B'){
            ret += (F(x + 1, y, F) + F(x, y + 1, F));
        }
        return ret % MOD;
    };
    int ret = 0;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) ret += F(i, j, F);
    cout << ret % MOD << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Sol();
    return 0;
}