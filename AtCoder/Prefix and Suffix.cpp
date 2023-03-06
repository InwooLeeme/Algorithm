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

int32_t main(){
    fastio;
    int n; cin >> n;
    string a,b; cin >> a >> b;
    int ret = 0;
    for(int i = 1; i <= n; i++){
        if(b.substr(0, i) == a.substr(n - i)) ret = i;
    }
    cout << 2*n - ret << "\n";
    return 0;
}