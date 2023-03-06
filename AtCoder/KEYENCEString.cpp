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
    string s; cin >> s;
    const int n = s.size();
    string k = "keyence";
    bool check = 0;
    for(int i = 0; i <= n; i++){
        for(int j = i; j <= n; j++){
            string sub = s.substr(0, i) + s.substr(j);
            if(sub == k){
                check = 1;
                break;
            }
        }
        if(check) break;
    }
    if(check) cout << "YES" << "\n";
    else cout << "NO" << "\n";
    return 0;
}