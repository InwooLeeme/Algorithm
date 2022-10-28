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
    int n; cin >> n;
    vector<string> v(n);
    for(auto& i : v) cin >> i;
    sort(v.begin(), v.end(), [&](string& a, string& b){
        if(a.size() == b.size()) return a < b;
        return a.size() < b.size();
    });
    for(auto& i : v) cout << i << "\n";
    return 0;
}