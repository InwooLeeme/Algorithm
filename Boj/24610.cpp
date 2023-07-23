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
    int n,m,s = 0; cin >> n >> m;
    vector<int> v(m),ret(m);
    for(auto& i : v) cin >> i;
    int i = 0;
    while (n and accumulate(v.begin(), v.end(), 0)){
        if(v[i]){
            ret[i]++;
            v[i]--;
            n--;
        }
        i = (i + 1) % m;
    } 
    for(auto& i : ret) cout << i << '\n';
    return 0;
}