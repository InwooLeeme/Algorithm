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
    using vi = vector<int>; using vvi = vector<vi>;
    int n,m; cin >> n >> m; vvi p(n + 1, vi(m + 1, 0));
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
        int t; cin >> t;
        p[i + 1][j + 1] = p[i][j + 1] + p[i + 1][j] - p[i][j] + t;
    }
    int mx = p[n][m];
    for(int r1 = 1; r1 <= n; r1++) for(int c1 = 1; c1 <= m; c1++){
        for(int r2 = r1; r2 <= n; r2++) for(int c2 = c1; c2 <= m; c2++){
            mx = max<int>(mx, p[r2][c2] - p[r1 - 1][c2] - p[r2][c1 - 1] + p[r1 - 1][c1 - 1]);
        }
    }
    cout << mx << '\n';
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}