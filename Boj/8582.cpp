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
    vector<int> v(n),a(n),b(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int mx = 0;
    for(int i = 0; i < n; i++) mx = max<int>(mx, v[i]), a[i] = mx;
    mx = 0;
    for(int i = n - 1; i >= 0; i--) mx = max<int>(mx, v[i]), b[i] = mx;
    for(int i = 0; i < n; i++) cout << a[i] << ' ' << b[i] << "\n";
    return 0;
}