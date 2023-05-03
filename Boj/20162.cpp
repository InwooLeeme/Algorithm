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

int I[1111],D[1111];

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> I[i];
    for(int i = 0; i < n; i++){
        D[i] = I[i];
        for(int j = 0; j < i; j++) if(I[i] > I[j]) D[i] = max<int>(D[i], D[j] + I[i]);
    }
    cout << *max_element(D, D + n) << "\n";
    return 0;
}