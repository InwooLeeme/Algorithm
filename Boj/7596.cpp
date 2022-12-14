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
    int T,tc = 1;
    while(cin >> T and T){
        cin.ignore();
        vector<string> v(T);
        for(int i = 0; i < T; i++){
            getline(cin, v[i]);
        }
        sort(v.begin(), v.end());
        cout << tc << "\n";
        for(auto& i : v) cout << i << "\n";
        tc++;
    }
    return 0;
}