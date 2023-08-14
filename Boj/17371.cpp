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

const int PRECISION = 0;

void Main(){
    using p = pair<int, int>; int n; cin >> n; vector<p> v(n); for(auto& [x,y] : v) cin >> x >> y;
    auto D = [&](p& a, p& b) -> int{ return ((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second)); };
    int mn = 2e9; int idx = -1;
    for(int i = 0; i < n; i++){
        int mx = 0;
        for(int j = 0; j < n; j++){
            mx = max<int>(mx, D(v[i], v[j]));
        }
        if(mn > mx) idx = i, mn = mx;
    }
    cout << (double)v[idx].first << " " << (double)v[idx].second << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}