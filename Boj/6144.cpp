# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
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
    vector<int> v(n + 1),w(n + 1), d(m + 1);
    for(int i = 0; i < n; i++) cin >> w[i] >> v[i];
    for(int i = 0; i < n; i++){
        for(int j = m; j >= w[i]; j--) d[j] = max<int>(d[j], d[j - w[i]] + v[i]);
    }
    cout << d[m] << "\n";
    return 0; 
}
