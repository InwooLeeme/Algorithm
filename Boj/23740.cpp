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
    vector<tii> v(n);
    for(auto& [a, b, c] : v) cin >> a >> b >> c;
    sort(v.begin(), v.end());
    auto& [st, en, cost] = v[0];
    vector<tii> ret;
    for(int i = 1; i < n; i++){
        auto& [sst, sen, scost] = v[i];
        if(en < sst){
            ret.push_back({st, en, cost});
            st = sst,en = sen,cost = scost;
        }
        else{
            en = max<int>(en, sen);
            cost = min<int>(cost, scost);
        }
    }
    ret.push_back({st, en, cost});
    sort(ret.begin(), ret.end());
    cout << ret.size() << "\n";
    for(auto& [a, b, c] : ret) cout << a << ' ' << b << ' ' << c << '\n';
    return 0;
}