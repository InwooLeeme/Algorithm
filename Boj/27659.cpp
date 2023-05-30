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
    int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        vector<int> v(n); iota(v.begin(), v.end(), 1);
        while(k--){
            int s; cin >> s;
            vector<int> nv{s};
            for(auto& i : v) if(i != s) nv.push_back(i);
            v = nv;
        }
        cout << v.back() << "\n";
    }
    return 0;
}