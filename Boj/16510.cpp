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
    int n,q; cin >> n >> q;
    vector<int> v(n),psum(n + 1);
    for(auto& i : v) cin >> i;
    for(int i = 0; i < n; i++) psum[i + 1] = v[i] + psum[i];
    while(q--){
        int t; cin >> t;
        cout << upper_bound(psum.begin(), psum.end(), t) - psum.begin() - 1 << "\n";
    }
    return 0;
}