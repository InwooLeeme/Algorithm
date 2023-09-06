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

int D[111][111'111];
int w[111];

void Main(){
    int n,m; cin >> n >> m;
    if(!m){
        cout << 0 << "\n"
        return 0;
    }
    constexpr int INF = int(1e18);
    for(int i = 1; i <= n; i++) cin >> w[i];
    for(int i = 0; i <= m; i++) D[0][i] = INF;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(j - w[i] >= 0) D[i][j] = min<int>(D[i - 1][j], D[i - 1][j - w[i]] + 1);
            else D[i][j] = D[i - 1][j];
        }
    }
    cout << (D[n][m] == INF ? -1 : D[n][m]) << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}