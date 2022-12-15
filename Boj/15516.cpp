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
    int n; cin >> n;
    vector<int> v(n),s(n);
    for(auto& i : v) cin >> i;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < i; j++) if(v[j] <= v[i]) cnt++;
        s[i] = cnt;
    }
    for(auto& i : s) cout << i << "\n";
    return 0;
}