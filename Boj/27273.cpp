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
    int x; cin >> x;
    set<int> ret;
    int mxcnt = 0,res = 0,mx = 0;
    for(int j = 1; j <= x; j++){
        set<int> div;
        for(int i = 1; i * i <= j; i++){
            if(j % i == 0){
                div.insert(i);
                div.insert(j / i);
            }
        }
        if(mxcnt < (int)div.size()){
            mxcnt = div.size();
            mx = j;
            ret = div;
        }
    }
    cout << mx << "\n" << mxcnt << "\n";
    return 0;
}