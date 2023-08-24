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


int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    int n,q; cin >> n >> q;
    vector<int> p(n + 1),pp(n + 1); for(int i = 0; i < n; i++){
        int t; cin >> t;
        p[i + 1] = p[i] + t;
        pp[i + 1] = pp[i] + t*t;
    }
    auto Query = [&](int l, int r) -> int{
        int t1 = p[r] - p[l - 1];
        int t2 = pp[r] - pp[l - 1];
        return ((t1 * t1) - t2) >> 1;
    };
    while(q--){
        int a,b; cin >> a >> b;
        cout << Query(a, b) << "\n";
    }
    return 0;
}