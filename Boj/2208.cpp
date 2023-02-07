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

int32_t main(){
    fastio;
    int n,m; cin >> n >> m;
    vector<int> pSum(n + 1);
    for(int i = 0,t; i < n; i++){
        cin >> t;
        pSum[i + 1] = pSum[i] + t;
    }
    int mx = 0,temp = 0;
    for(int i = m - 1; i < n; i++){
        temp = min<int>(temp ,pSum[i - m + 1]);
        mx = max<int>(mx, pSum[i + 1] - temp);
    }
    cout << mx << '\n';
    return 0;
}