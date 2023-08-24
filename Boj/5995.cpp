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

int d[45505];
int w[555];

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    int h,n; cin >> h >> n;
    for(int i = 0; i < n; i++) cin >> w[i];
    for(int i = 0; i < n; i++){
        if(w[i] > h) continue;
        for(int j = h; j >= w[i]; j--) d[j] = max<int>(d[j], d[j - w[i]] + w[i]);
    }
    cout << d[h] << "\n";
    return 0;
}