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

#define int int_fast64_t

constexpr int MOD = 1234567;

int d[1001][10];

int Sol(int x){
    int ret = 0;
    for(int i = 0; i < 10; i++) ret += d[x][i];
    return ret;
}

int32_t main(){
    fastio;
    int t; cin >> t;
    for(int i = 0; i < 10; i++) d[1][i] = 1;
    for(int i = 2; i < 1001; i++){
        d[i][0] = (d[i - 1][7]) % MOD;
        d[i][1] = (d[i - 1][2] + d[i - 1][4]) % MOD;
        d[i][2] = (d[i - 1][1] + d[i - 1][3] + d[i - 1][5]) % MOD;
        d[i][3] = (d[i - 1][2] + d[i - 1][6]) % MOD;
        d[i][4] = (d[i - 1][1] + d[i - 1][5] + d[i - 1][7]) % MOD;
        d[i][5] = (d[i - 1][2] + d[i - 1][4] + d[i - 1][6] + d[i - 1][8]) % MOD;
        d[i][6] = (d[i - 1][3] + d[i - 1][5] + d[i - 1][9]) % MOD;
        d[i][7] = (d[i - 1][4] + d[i - 1][8] + d[i - 1][0]) % MOD;
        d[i][8] = (d[i - 1][5] + d[i - 1][7] + d[i - 1][9]) % MOD;
        d[i][9] = (d[i - 1][6] + d[i - 1][8]) % MOD;
    }
    while(t--){
        int n; cin >> n;
        cout << Sol(n) % MOD << "\n";
    }
    return 0;
}  