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

int v[111'1111],d[111'1111];

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n,mx = 0; cin >> n;
    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 1; i <= n; i++){
        d[v[i]] = max<int>(d[v[i]], d[v[i] - 1] + 1);
        mx = max<int>(mx, d[v[i]]);
    }
    cout << mx << "\n";
    return 0;
}