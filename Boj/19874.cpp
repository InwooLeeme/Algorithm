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
    int n; cin >> n;
    vector<int> p(n + 1); for(int i = 1,t; i <= n; i++){
        cin >> t;
        p[i] = p[i - 1] + t;
    }
    int ret = -1,mn = int(2e9);
    for(int i = 1; i <= n; i++){
        if(abs(p[i] - (p[n] - p[i])) < mn){
            mn = abs(p[i] - (p[n] - p[i]));
            ret = i;
        }
    }
    cout << ret << "\n";
    return 0;
}