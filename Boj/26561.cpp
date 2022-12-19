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

#define int int64_t

int32_t main(){
    fastio;
    int T; cin >> T;
    while(T--){
        int p,t; cin >> p >> t;
        for(int i = 1; i <= t; i++){
            if(i % 7 == 0) p--;
            if(i % 4 == 0) p++;
        }
        cout << p << "\n";
    }
    return 0;
}