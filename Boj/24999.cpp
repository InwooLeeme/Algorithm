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
    int n,m,k,ret = 0; cin >> n >> m >> k;
    vector<int> a(n),b(m);
    for(auto& i : a) cin >> i; for(auto& i : b) cin >> i;
    sort(a.begin(), a.end());  sort(b.begin(), b.end());
    for(int i = 0; i < n; i++){
        ret += (upper_bound(b.begin(), b.end(), k + a[i]) - lower_bound(b.begin(), b.end(), a[i] - k));
    }
    cout << ret << "\n";
    return 0;
}