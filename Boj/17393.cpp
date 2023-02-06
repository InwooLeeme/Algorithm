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
    vector<int> a(n),b(n);
    for(auto& i : a) cin >> i;
    for(auto& i : b) cin >> i;
    for(int i = 0; i < n; i++) cout << upper_bound(b.begin() + i + 1, b.end(), a[i]) - (b.begin() + i + 1) << ' ';
    return 0;
}