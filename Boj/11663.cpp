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
    int n,m; cin >> n >> m;
    vector<int> v(n); for(auto& i : v) cin >> i;
    sort(v.begin(), v.end());
    while(m--){
        int a,b; cin >> a >> b;
        cout << upper_bound(v.begin(), v.end(), b) - lower_bound(v.begin(), v.end(), a) << "\n";
    }
    return 0;
}