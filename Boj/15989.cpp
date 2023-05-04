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

int D[10011][4];

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t;
    D[0][1] = D[1][1] = 1;
    for(int i = 2; i < 10011; i++){
        D[i][1] = D[i - 1][1];
        D[i][2] = D[i - 2][1] + D[i - 2][2];
        if(i >= 3) D[i][3] = D[i - 3][1] + D[i - 3][2] + D[i - 3][3];
    }
    while(t--){
        int n; cin >> n;
        cout << D[n][1] + D[n][2] + D[n][3] << "\n";
    }
    return 0;
}