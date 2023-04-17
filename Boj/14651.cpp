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

constexpr int MOD = 1e9 + 9;

int d[33'334];

int32_t main(){
    fastio;
    int n; cin >> n;
    d[1] = 0,d[2] = 2,d[3] = 6;
    for(int i = 4; i <= n; i++) d[i] = d[i - 1] * 3 % MOD;
    cout << d[n] << "\n";
    return 0;
} 