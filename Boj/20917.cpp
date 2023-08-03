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

void Sol(){
    int n,m; cin >> n >> m; vector<int> v(n); for(auto& i : v) cin >> i;
    sort(v.begin(), v.end());
    function<int(int)> Check = [&](int mid){
        int ret = 1,prv = v[0];
        for(int i = 1; i < n; i++) if((v[i] - prv) >= mid) ret++,prv = v[i];
        return ret < m;
    };
    int lo = 0, hi = int(1e18);
    while(lo + 1 < hi){
        int mid = lo + hi >> 1;
        if(!Check(mid)) lo = mid;
        else hi = mid;
    }
    cout << lo << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    int t; cin >> t; while(t--) Sol();
    return 0;
}