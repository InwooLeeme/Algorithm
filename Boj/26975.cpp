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

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    int mx = 0,ret = 0;
    vector<int> v(n); for(auto& i : v) cin >> i;
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        if((n - i)* v[i] > mx){
            mx = (n - i)*v[i];
            ret = v[i];
        }
    }    
    cout << mx << " " << ret << "\n";
    return 0;
}