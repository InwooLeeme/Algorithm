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

int d[111111];

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int c,n; cin >> c >> n;
    vector<int> w(n),v(n);
    for(int i = 0; i < n; i++) cin >> w[i] >> v[i];
    for(int i = 0; i < n; i++){
        for(int j = w[i]; j <= 100000; j++){
            d[j] = max<int>(d[j], d[j - w[i]] + v[i]);
        }
    }
    for(int i = 0; i < 111111; i++){
        if(d[i] >= c){
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}