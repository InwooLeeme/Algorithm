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

void Sol(){
    int n,m; cin >> n >> m;
    const int INF = int(2e18);
    vector<vector<int>> d(n + 1, vector<int>(m + 1, INF));
    vector<int> v(n + 1),u(m + 1); 
    for(int i = 1; i <= n; i++) cin >> v[i]; for(int i = 1; i <= m; i++) cin >> u[i];
    for(int i = 0; i <= m; i++) d[0][i] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            d[i][j] = min<int>({d[i][j], d[i][j - 1], d[i - 1][j - 1] + v[i] * u[j]});
        }
    }
    int ret = INF;
    for(int i = 1; i <= m; i++) ret = min<int>(ret, d[n][i]);
    cout << ret << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Sol();
    return 0;
}