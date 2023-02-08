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

constexpr int INF = int(1e18);

int32_t main(){
    fastio;
    int n,m,k; cin >> n >> m >> k; cin.ignore();
    vector<string> v(n);
    for(auto& i : v) cin >> i;
    vector<vector<int>> dist(n * n ,vector<int>(n * n, INF));
    for(int i = 0; i < n * n; i++) dist[i][i] = 0;
    // Make Graph
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++){
            if(v[i][j] == v[i][j + 1]) dist[i * n + j][i * n + j + 1] = dist[i * n + j + 1][i * n + j] = m;
            else dist[i * n + j][i * n + j + 1] = dist[i * n + j + 1][i * n + j] = k;
        }
    }
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n; j++){
            if(v[i][j] == v[i + 1][j]) dist[(i + 1) * n + j][i * n + j] = dist[i * n + j][(i + 1) * n + j] = m;
            else dist[(i + 1) * n + j][i * n + j] = dist[i * n + j][(i + 1) * n + j] = k;
        }
    }
    // floyd
    for(int k = 0; k < n * n; k++){
        for(int i = 0; i < n * n; i++){
            for(int j = 0; j < n * n; j++){
                dist[i][j] = min<int>(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int ret = 0;
    for(int i = 0; i < n * n; i++){
        for(int j = i + 1; j < n * n; j++){
            if(dist[i][j] != INF) ret = max<int>(ret, dist[i][j]);
        }
    }
    cout << ret << "\n";
    return 0;
}