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

int Sol(){
    int ret = 0,k,v; cin >> k >> v;
    for(int i = 0; i <= k; i++){
        for(int j = 0; j <= k; j++){
            for(int l = 0; l <= k; l++){
                if(abs(i - j) <= v and abs(i - l) <= v and abs(j - l) <= v) ret++;
            }
        }
    }
    return ret;
}

int32_t main(){
    fastio;
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++){
        cout << "Case #" << tc << ": " << Sol() << "\n";
    }
    return 0;
}