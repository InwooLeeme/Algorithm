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

bool IsPrime(int x){
    if(x <= 1) return 0;
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0) return 0;
    }
    return 1;
}

int32_t main(){
    fastio;
    int N,ret = 1,cnt = 0; cin >> N;
    for(int i = 0; i < N; i++){
        int x; cin >> x;
        if(IsPrime(x)){
            ret = lcm(ret, x);
            cnt++;
        }
    }
    cout << (cnt != 0 ? ret : -1) << "\n";
    return 0;
}