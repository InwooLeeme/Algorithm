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
    int n,m,ret = 0; cin >> n >> m; vector<int> w(n); for(auto& i : w) cin >> i;
    sort(w.begin(), w.end());
    int l = 0, r = n - 1;
    while(l <= r){
        if(w[l] + w[r] > m) r--,ret++;
        else r--,l++,ret++;
    }
    cout << ret << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Sol();
    return 0;
}