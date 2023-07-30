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
    int n,mx = 0; cin >> n; vector<int> v(n); for(auto& i : v) cin >> i, mx = max<int>(mx, i);
    vector<int> cnt(mx + 1, 0),ret(n);
    for(auto& i : v) cnt[i]++;
    for(int i = 0; i < n; i++){
        for(int j = 1; j * j <= v[i]; j++){
            if(v[i] % j != 0) continue;
            ret[i] += cnt[j];
            if(j != v[i] / j) ret[i] += cnt[v[i] / j];
        }
    }
    for(auto& i : ret) cout << i - 1 << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Sol();
    return 0;
}