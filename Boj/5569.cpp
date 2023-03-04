#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

constexpr int MOD = 1e5;

int dp[111][111][2][2];
int n,m;

int Sol(int x,int y, int d, int flag){
    if(x == n and y == m) return 1;
    int& ret = dp[x][y][d][flag];
    if(ret != -1) return ret; ret = 0;
    if(x + 1 <= n and (d || !flag)) ret += Sol(x + 1, y, 1, !d);
    if(y + 1 <= m and (!d || !flag)) ret += Sol(x, y + 1, 0, d);
    return ret %= MOD;
}

int32_t main(){
    fastio;
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    cout << (Sol(1, 1, 1, 1) + Sol(1, 1, 0, 1)) % MOD << "\n";
    return 0;
}