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

int D[33];

int32_t main(){
    fastio;
    int T; cin >> T;
    D[1] = 0, D[2] = 1;
    for(int i = 3; i < 33; i++) D[i] = (i - 1)*(D[i - 1] + D[i - 2]);
    while(T--){
        int x; cin >> x;
        cout << D[x] << "\n";
    }
    return 0;
}