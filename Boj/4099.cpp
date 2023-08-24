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

const int PRECISION = 0;

void Main(){
    const int MOD = int(1e6);
    int d[1111] = {1, 1};
    for(int i = 2; i < 1111; i++){
        for(int j = 0; j < i; j++) d[i] = (d[i] + d[j] * d[i - 1 - j]) % MOD;
    }
    int n; while(cin >> n and n){
        cout << d[n] << "\n";
    }
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}