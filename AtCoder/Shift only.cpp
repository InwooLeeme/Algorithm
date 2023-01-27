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
    int n,ret = 0; cin >> n;
    vector<int> v(n);
    for(auto& i : v){
        cin >> i;
        if(i & 1){
            cout << 0 << "\n";
            return 0;
        }
    }
    bool flag = 1;
    while(flag){
        for(auto& i : v){
            if(i & 1){
                flag = 0;
                break;
            }
        }
        for(auto& i : v) i /= 2;
        ret++;
    }
    cout << ret - 1 << "\n";
    return 0;
}