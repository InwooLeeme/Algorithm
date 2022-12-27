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

using pis = pair<int, string>;

int32_t main(){
    fastio;
    int n,d,k,cnt = 0,sum = 0; cin >> n >> d >> k; cin.ignore();
    vector<pis> v(n);
    for(auto& [cost, x] : v) cin >> x >> cost;
    sort(v.begin(), v.end());
    vector<string> ret;
    for(int i = n - 1; i >= n - k; i--){
        sum += v[i].first;
        ret.push_back(v[i].second);
        if(sum >= d){
            cout << ret.size() << "\n";
            for(auto& i : ret) cout << i << ", YOU ARE FIRED!\n";
            return 0;
        }
    }
    cout << "impossible" << "\n";
    return 0;
}