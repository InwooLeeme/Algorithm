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
    int n,t1 = 0,t2 = 0; cin >> n;
    vector<int> a(n),b(n),v(n);
    for(auto& i : a) cin >> i; 
    for(auto& i : b) cin >> i;
    iota(v.begin(), v.end(), 1);
    int idx = 1;
    do{
        if(v == a) t1 = idx;
        if(v == b) t2 = idx;
        idx++;
    }while(next_permutation(v.begin(), v.end()));
    cout << abs(t2 - t1) << "\n";
    return 0;
}