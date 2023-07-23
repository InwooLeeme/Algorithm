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
    vector<int> v(n); for(auto& i : v) cin >> i;
    if(v[1] - v[0] == v[2] - v[1]){
        int r = v[1] - v[0];
        cout << v[n - 1] + r << "\n";
    }
    else{
        int d = v[2] / v[1];
        cout << v[n - 1] * d << "\n";
    }
    return 0;
}