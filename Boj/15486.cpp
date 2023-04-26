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
    int n; cin >> n;
    vector<int> d(n + 3),t(n + 2),p(n + 2);
    for(int i = 1; i <= n; i++) cin >> t[i] >> p[i];
    for(int i = n; i >= 1; i--){
        if(i + t[i] > n + 1) d[i] = d[i + 1];
        else d[i] = max<int>(d[i + 1], d[i + t[i]] + p[i]);
    }
    cout << d[1] << "\n";
    return 0;
}