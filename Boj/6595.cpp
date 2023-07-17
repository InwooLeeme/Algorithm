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

using p = pair<int, int>;

const int INF = int(2e18);

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n,tc = 1;
    while(cin >> n and n){
        vector<p> v(n);
        for(auto& [x, y] : v) cin >> x >> y;
        vector<vector<double>> dist(n + 1, vector<double>(n + 1, INF));
        for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++){
            dist[i][j] = sqrt((v[i].first - v[j].first) * (v[i].first - v[j].first) + (v[i].second - v[j].second) * (v[i].second - v[j].second));
            dist[j][i] = sqrt((v[i].first - v[j].first) * (v[i].first - v[j].first) + (v[i].second - v[j].second) * (v[i].second - v[j].second));
        }
        // floyd
        for(int k = 0; k < n; k++) for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
            dist[i][j] = min<double>(dist[i][j], max<double>(dist[i][k], dist[k][j]));
        }
        cout << "Scenario #" << tc << "\n";
        cout << "Frog Distance = " << fixed << setprecision(3) << dist[0][1] << "\n\n";
        tc++;
    }
    return 0;
}