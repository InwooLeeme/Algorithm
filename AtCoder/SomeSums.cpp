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

int n,a,b,ret;

int Check(int x){
    int ret = 0;
    while(x){
        ret += (x % 10);
        x /= 10;
    }
    return a <= ret and ret <= b;
}

int32_t main(){
    fastio;
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i++){
        if(Check(i)) ret += i;
    }
    cout << ret << "\n";
    return 0;
}