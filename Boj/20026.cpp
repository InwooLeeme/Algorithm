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

using tii = tuple<int, int, int>;

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    vector<tii> e;
    for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++) {int t; cin >> t,e.push_back({t, i, j});}
    sort(e.begin(), e.end());
    int mn = 0,mx = 0,r = 1,idx = 0;
    for(int i = 0; i < n - 1; i++){
        auto [c,a, b] = e[i];
        mn += c;
    }
    for(int i = 0; i < n - 1; i++,r++){
        auto& [c,a,b] = e[idx];
        mx += c;
        idx += r;
    }
    cout << mn << ' ' << mx << "\n";
    return 0;
}