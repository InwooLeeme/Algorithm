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

map<char, char> M;

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s; int q; cin >> s >> q;
    for(auto& i : s) M[i] = i;
    while(q--){
        int t; cin >> t;
        if(t == 2){ for(auto& i : s) cout << M[i]; cout << "\n"; }
        else{
            char a,b; cin >> a >> b;
            for(auto& [x, y] : M) if(y == a) M[x] = b;
        }
    }
    return 0;
}