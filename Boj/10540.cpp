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

int32_t main(){
    fastio;
    int N,mxx = 0,mxy = 0, mnx = int(1e9),mny = int(1e9); cin >> N;
    for(int i = 0; i < N; i++){
        int a,b; cin >> a >> b;
        mxx = max<int>(mxx, a);
        mxy = max<int>(mxy, b);
        mnx = min<int>(mnx, a);
        mny = min<int>(mny, b);
    }
    int D = max(mxx - mnx, mxy - mny);
    cout << D * D << "\n";
    return 0;
}