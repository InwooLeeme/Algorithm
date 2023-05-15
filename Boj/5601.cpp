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

using pt = pair<int, int>;
int n,m,q;
int D[22][22], vist[22][22];

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> q;
    while(q--){
        int a,b; cin >> a >> b;
        vist[a][b] = 1;
    }
    D[1][1] = 1;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++){
        if(!vist[i][j + 1]) D[i][j + 1] += D[i][j];
        if(!vist[i + 1][j]) D[i + 1][j] += D[i][j];
    }
    cout << D[n][m] << "\n";
    return 0;
}