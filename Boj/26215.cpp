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
    int n,sum = 0,mx = 0; cin >> n;
    for(int i = 0,x; i < n; i++){
        cin >> x; 
        sum += x;
        mx = max<int>(mx, x);
    }
    int ret = max<int>(mx, (sum + 1) / 2);
    cout << (ret > 1440 ? -1 : ret) << "\n";
    return 0;
}