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

using pt = pair<int, int>;

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n,ret = 0; cin >> n;
    vector<pt> v(n);
    for(auto& [a, b] : v) cin >> a >> b;
    for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++) for(int k = j + 1; k < n; k++){
        auto GetDist = [&](pt& a, pt& b) -> int{ return ((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second)); };
        auto Check = [&](pt& a, pt& b, pt& c) -> bool{
            auto A = GetDist(a, b),B = GetDist(b, c), C = GetDist(a, c);
            return (A + B == C or B + C == A or A + C == B);
        };
        if(Check(v[i], v[j], v[k])) ret++;
    }
    cout << ret << '\n';
    return 0;
}