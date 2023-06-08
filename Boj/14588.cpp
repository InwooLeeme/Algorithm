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

const int INF = int(2e9);

vector<vector<int>> dist(333, vector<int>(333, INF));

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n,m;
    cin >> n;
    vector<pt> v(n + 1);
    for(int i = 1; i <= n; i++) cin >> v[i].first >> v[i].second;
    for(int i = 0; i < 333; i++) dist[i][i] = 0;
    auto IsInside = [&](int a, int b,int c) -> bool{
        return a <= b and b <= c;
    };
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(IsInside(v[i].first, v[j].first, v[i].second) or IsInside(v[i].first, v[j].second, v[i].second) or IsInside(v[j].first, v[i].first, v[j].second) or IsInside(v[j].first, v[i].second, v[j].second)){
                dist[i][j] = 1;
                dist[j][i] = 1;
            }
        }
    }
    // floyd
    for(int k = 0; k <= n; k++) for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++){
        dist[i][j] = min<int>(dist[i][j], dist[i][k] + dist[k][j]);
    }
    cin >> m;
    while(m--){
        int a,b; cin >> a >> b; 
        cout << (dist[a][b] == INF ? -1 : dist[a][b]) << "\n";
    }
    return 0;
}