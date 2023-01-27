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

int32_t main(){
    fastio;
    int n,m,c,cnt = 0; cin >> n >> m >> c;
    vector<int> v(m);
    for(auto& i : v) cin >> i;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0,t; j < m; j++){
            cin >> t;
            sum += (v[j] * t);
        }
        if(sum + c> 0) cnt++;
    }
    cout << cnt << "\n";
    return 0;
}