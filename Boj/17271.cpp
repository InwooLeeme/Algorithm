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

constexpr int MOD = 1e9 + 7;

int d[11111];

int32_t main(){
    fastio;
    int n,m; cin >> n >> m;
    d[0] = 1;
    for(int i = 1; i <= n; i++){
        d[i] = d[i - 1];
        if(i >= m) d[i] = (d[i] + d[i - m]) % MOD;
    }
    cout << d[n] << "\n";
    return 0;
}