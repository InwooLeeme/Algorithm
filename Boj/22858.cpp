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
    int n,k; cin >> n >> k;
    vector<int> d(n + 1),retv(n + 1);
    for(int i = 1; i <= n; i++) cin >> retv[i];
    for(int i = 1; i <= n; i++) cin >> d[i];
    auto ShuffleV = [&](vector<int>& v) -> vector<int>{
        vector<int> ret(n + 1);
        for(int i = 1; i <= n; i++) ret[d[i]] = v[i];        
        return ret;
    };
    while(k--) retv = ShuffleV(retv);
    for(int i = 1; i <= n; i++) cout << retv[i] << " ";
    return 0;
}