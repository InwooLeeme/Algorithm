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
    int n,m; cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m, 0));
    for(auto& i : v){
        for(auto& j : i) cin >> j;
    }
    int mx = 0;
    for(int i = 0; i < m; i++){
        for(int j = i + 1; j < m; j++){
            for(int k = j + 1; k < m; k++){
                int sum = 0;
                for(int t = 0; t < n; t++){
                    sum += max<int>({v[t][i], v[t][j], v[t][k]});
                }
                mx = max<int>(mx, sum);
            }
        }
    }
    cout << mx << "\n";
    return 0;
}