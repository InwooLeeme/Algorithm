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

int n,p,q;
map<int, int> D;

int F(int n){
    if(D.count(n)) return D[n];
    return D[n] = F(floor(n / p)) + F(floor(n / q));
}

int32_t main(){
    fastio;
    cin >> n >> p >> q;
    D[0] = 1;
    cout << F(n) << "\n";
    return 0;  
}