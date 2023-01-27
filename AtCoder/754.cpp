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
    string s; cin >> s;
    int sz = s.size(),mn = 1e9;
    for(int i = 0; i < sz - 2; i++){
        auto cur = stoi(s.substr(i, 3));
        mn = min<int>(mn, abs(753 - cur));
    }
    cout << mn << "\n";
    return 0;
}