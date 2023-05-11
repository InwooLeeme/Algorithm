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

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n,k; cin >> k >> n;
    vector<int> coins(n);
    for(auto& i : coins) cin >> i;
    int mx = *max_element(coins.begin(), coins.end());
    vector<int> d(k + 1, 0);
    sort(coins.begin(), coins.end());
    d[0] = 1;
    for(auto& x : coins){
        for(int i = 1; i <= k; i++) if(i >= x) d[i] += d[i - x];
    }
    cout << d[k] << "\n";
    return 0;
}