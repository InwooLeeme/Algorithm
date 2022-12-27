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

int Sol(){
    int n,q; cin >> n >> q;
    vector<int> d(n + 1, 0);
    d[1] = d[2] = 1;
    for(int i = 3; i <= n; i++) d[i] = (d[i - 1] + d[i - 2]) % q;
    return d[n] % q;
}

int32_t main(){
    fastio;
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++){
        auto ret = Sol();
        cout << "Case #" <<  tc << ": " << ret << "\n";
    }
    return 0;
}