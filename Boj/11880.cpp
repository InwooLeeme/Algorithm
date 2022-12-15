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
    int T; cin >> T;
    while(T--){
        int a,b,c; cin >> a >> b >> c;
        cout << min<int>({(a * a) + ((b + c) * (b + c)), (b * b) + ((a + c) * (a + c)), (c * c) + ((a + b) * (a + b))}) << "\n";
    }
    return 0;
}