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

int32_t main(){
    fastio;
    int n,m,k,q; cin >> n >> m >> k >> q;
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, int(1e9)));
    for(int i = 0; i <= n; i++) dist[i][i] = 0;
    while(m--){
        int a,b,c; cin >> a >> b >> c;
        dist[a][b] = min<int>(dist[a][b], c);
    }
    // floyd
    for(int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++){
        dist[i][j] = min<int>(dist[i][j], dist[i][k] + dist[k][j]);
    }
    int cnt = 0,ret = 0;
    while(q--){
        int a,b,mn = int(1e9); cin >> a >> b;
        bool check = 0;
        for(int i = 1; i <= k; i++){
            if(dist[a][i] != int(1e9) and dist[i][b] != int(1e9)){
                check = 1;
                mn = min<int>(mn, dist[a][i] + dist[i][b]);
            }
        }
        if(check) cnt++,ret += mn;
    }
    cout << cnt << "\n" << ret << "\n";
    return 0;
}