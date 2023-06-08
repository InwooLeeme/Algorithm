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
    int n,x; cin >> n >> x; n++;
    const int MOD = 1e9 + 7;
    int ret = 0,flag = 1;
    while(n--){
        int a,b; cin >> a >> b;
        if(flag) ret = a,flag = 0;
        else ret = (ret * x + a) % MOD;
    }
    cout << ret << "\n";
    return 0;
}