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

const int MOD = 1e9 + 7;

struct Poly{
    int x,expo;
};

int __pow(int x, int n){
    int ret = 1;
    while(n){
        if(n & 1) ret = x * ret % MOD;
        n >>= 1;
        x = x * x % MOD;
    }
    return ret % MOD;
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    vector<Poly> p(n);
    for(auto& [c, x] : p) cin >> c >> x;
    // f'x cal Poly
    int ret = 0,x = 2;
    for(auto& [val, expo] : p){
        if(!val or !expo) continue;
        int s = 1;
        if(expo - 1 > 0) s = __pow(x, expo - 1);
        ret += (val * expo % MOD * s) % MOD;
    }
    cout << ret % MOD << "\n";
    return 0;
}