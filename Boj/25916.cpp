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
    int mx = 0,l = 0,r = 0,sum = 0;
    for(int l = 0; l < n; l++){
        while(r < n and sum + v[r] <= m) sum += v[r++];
        mx = max<int>(mx, sum);
        sum -= v[l];
    }
    cout << mx << "\n";
    return 0;
}