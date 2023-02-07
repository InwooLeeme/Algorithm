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

constexpr int INF = 1e9;
vector<vector<int>> dist(333, vector<int>(333, INF));

int32_t main(){
    fastio;
    int n,m; cin >> n >> m;
    vector<int> a(333);
    for(int i = 1; i <= n; i++) dist[i][i] = 0;
    while(m--){
        int s; cin >> s;
        for(int i = 0; i < s; i++) cin >> a[i];
        for(int i = 0; i < s; i++){
            for(int j = i + 1; j < s; j++){
                dist[a[j]][a[i]] = dist[a[i]][a[j]] = 1;
            }
        }
    }
    // floyd
    for(int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) dist[i][j] = min<int>(dist[i][j], dist[i][k] + dist[k][j]);
    int ret = INF;
    for(int i = 1; i <= n; i++){
        int sum = 0;
        for(int j = 1; j <= n; j++) sum += dist[i][j];
        ret = min<int>(ret, sum);
    }
    cout << ret * 100 / (n - 1) << "\n";
    return 0;
}