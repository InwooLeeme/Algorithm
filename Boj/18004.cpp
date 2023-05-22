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
    int a,b; cin >> a >> b;
    if(a > b){
        int ret = 0;
        while(a > b){
            if(a & 1) a++;
            else a >>= 1;
            ret++;
        }
        cout << ret + b - a << '\n';
    }
    else if(a == b) cout << 0 << "\n";
    else cout << b - a << "\n";
    return 0;
}