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
    int n; cin >> n;
    if(!n) cout << 0 << "\n";
    else if(n == 1) cout  << 1 << "\n";
    else{
        int cnt = 1;
        for(int i = 1; ; i <<= 1,cnt++){
            if(i >= n){
                cout << cnt << "\n";
                return 0;
            }
        }
    }
    return 0;
}