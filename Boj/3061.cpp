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
    int n,ret = 0; cin >> n;
    vector<int> v(n); for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++) ret += v[i] > v[j];     
    cout << ret << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    int t; cin >> t;
    while(t--) Sol();
    return 0;
}