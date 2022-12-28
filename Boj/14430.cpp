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

#define int int_fast64_t

int D[555][555],v[555][555];

int32_t main(){
    fastio;
    int n,m; cin >> n >> m;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) cin >> v[i][j];
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++){
        D[i][j] = max<int>(D[i - 1][j], D[i][j - 1]) + v[i][j];
    }
    cout << D[n][m] << "\n";
    return 0;
}