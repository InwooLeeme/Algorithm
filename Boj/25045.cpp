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
    int n,m; cin >> n >> m; vector<int> v(n),w(m); for(auto& i : v) cin >> i; for(auto& i : w) cin >> i;
    sort(v.rbegin(), v.rend()); sort(w.begin(), w.end());
    int ret = 0;
    for(int i = 0; i < min<int>(n, m); i++){
        if(v[i] - w[i] <= 0) continue;
        ret += abs(v[i] - w[i]);
    }
    cout << ret << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}