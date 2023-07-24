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
    int n,m,k,mx = 0,ret = 0; cin >> n >> m >> k;
    vector<int> v(n); for(auto& i : v) cin >> i,mx = max<int>(mx, i);
    for(int i = 1; i <= mx; i++){
        int sum = 0;
        for(auto& j : v){
            int q = j / i,r = j % i,s = 0,spent = 0,add = 0;
            if(r) spent = q*m;
            else spent = (q - 1)*m;
            add = i*q*k - spent;
            if(add < 0) continue;
            sum += add;
        }
        ret = max<int>(ret, sum);
    }
    cout << ret << "\n";
    return 0;
}