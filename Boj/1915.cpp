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

int n,m,d[1111][1111];

int32_t main(){
    fastio;
    cin >> n >> m;
    int mx = 0;
    for(int i = 1; i <= n; i++){
        string s; cin >> s;
        for(int j = 1; j <= m; j++){
            if(s[j - 1] == '0') continue;
            d[i][j] = min<int>({d[i - 1][j], d[i][j - 1], d[i - 1][j - 1]}) + 1;
            mx = max<int>(mx, d[i][j]);
        }
    }
    cout << mx * mx << "\n";
    return 0;
}