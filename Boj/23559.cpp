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

using p = pair<int, int>;

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n,x; cin >> n >> x;
    int ret = 0,cost = 1000*n;
    vector<p> v(n); for(auto& [a, b] : v) cin >> a >> b;
    sort(v.begin(), v.end(), [&](p& a, p& b){
        return (a.first - a.second > b.first - b.second ? 1 : 0);
    });
    for(auto& [a, b] : v){
        if(a > b and x >= cost + 4000) cost += 4000,ret += a;
        else ret += b;
    }
    cout << ret << "\n";
    return 0;
}