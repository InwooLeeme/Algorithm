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

using pii = pair<int, int>;

void testcase(){
    int n; cin >> n;
    vector<pii> v(n);
    for(auto& [a, b] : v) cin >> a >> b;
    int ret = 1; 
    sort(v.begin(), v.end());
    int mn = min<int>(1e9, v[0].second);
    for(int i = 1; i < n; i++){
        if(mn > v[i].second) ret++;
        mn = min<int>(mn, v[i].second);
    }
    cout << ret << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while(t--) testcase();
    return 0;
}