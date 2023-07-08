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
    int x,y,m; cin >> x >> y >> m;
    int mx = 0;
    for(int i = 0; i <= 1000; i++) for(int j = 0; j <= 1000; j++){
        if(x*i + y*j > m) continue;
        mx = max<int>(mx, x*i + y*j);
    }
    cout << mx << '\n';
    return 0;
}