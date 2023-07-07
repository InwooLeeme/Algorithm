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
    int t; cin >> t;
    while(t--){
        double r,b; cin >> r >> b;
        if(sqrt(2)*r <= b) cout << fixed << setprecision(3) << 2*r*r << '\n';
        else cout << fixed << setprecision(3) << b*sqrt(4*r*r - b*b) << '\n';
    }
    return 0;
}