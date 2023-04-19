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
    int n; cin >> n;
    vector<int> a(n),b(n),LIS;
    for(int i = 0,t; i < n; i++){
        cin >> t;
        a[t - 1] = i;
    }
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        b[i] = a[t - 1];
    }
    for(int i = 0; i < n; i++){
        if(LIS.empty() || LIS.back() < b[i]) LIS.push_back(b[i]);
        else *lower_bound(LIS.begin(), LIS.end(), b[i]) = b[i];
    }
    cout << LIS.size() << "\n";
    return 0;
}