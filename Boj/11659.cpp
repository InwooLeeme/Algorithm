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
    int n,q; cin >> n >> q;
    vector<int> v(n),pSum(n + 1);
    for(auto& i : v) cin >> i;
    partial_sum(v.begin(), v.end(), pSum.begin() + 1);
    while(q--){
        int x,y; cin >> x >> y; 
        cout << pSum[y] - pSum[x - 1] << "\n";
    }
    return 0;
}