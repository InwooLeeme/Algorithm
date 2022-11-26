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

int32_t main(){
    fastio;
    int lim,c,mx = 0; cin >> lim >> c;
    vector<int> v(c);
    for(auto& i : v) cin >> i;
    for(int i = 1; i < (1 << c); i++){
        int sum = 0;
        for(int j = 0; j < c; j++) if(i & (1 << j)) sum += v[j];
        if(sum <= lim) mx = max(mx, sum);
    }
    cout << mx << "\n";
    return 0;
}