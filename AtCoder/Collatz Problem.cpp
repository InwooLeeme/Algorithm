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

int f(int x){
    return (x % 2 == 0 ? x / 2 : 3*x + 1);
}

int32_t main(){
    fastio;
    int s,idx = 1; cin >> s;
    map<int, int> M;
    //M[s];
    while(1){
        if(M[s] > 0){
            cout << idx << "\n";
            return 0;
        }
        M[s]++;
        s = f(s);
        idx++;
    }
    return 0;
}