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
    string s; cin >> s;
    map<char, int> M;
    for(auto& i : s) M[i]++;
    bool even = 0,odd = 0;
    for(auto& [a, b] : M){
        if(b & 1) odd = 1;
        else even = 1;
    }
    if(odd and even) cout << "0/1";
    else if(odd) cout << 1;
    else cout << 0;
    return 0;
}