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

#define int int64_t

int D[1111];

int T(int n,bool flag){
    if(flag) return (1LL << n) - 1;
    if(n == 1) return 1;
    int& ret = D[n];
    if(ret) return ret;
    ret = int(1e18);
    for(int i = 0; i < min<int>(50, n); i++){
        ret = min<int>(ret, 2 * T(n - i, 0) + T(i, 1));
    }
    return ret;
}

int32_t main(){
    fastio;
    int n,tc = 0;
    while(cin >> n) cout << "Case " << ++tc << ": " << T(n, 0) << "\n";
    return 0;
}