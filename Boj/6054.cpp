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

const int INF = int(2e18);

vector<pt> g[1010];

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    // graph construct
    vector<int> cost(n + 1);
    for(int i = 1; i <= n; i++){
        int t,m; cin >> t >> m;
        cost[i] = t;
        while(m--){
            int x; cin >> x;
            g[i].push_back({t, x});
        }
    }
    auto Dijkstra = [&](int st = 1) -> vector<int>{
        vector<int> dist(n + 2, INF);
        priority_queue<pt, vector<pt>, greater<pt>> PQ;
        PQ.push({dist[st] = 0, st});
        while(PQ.size()){
            auto [cost, cur] = PQ.top(); PQ.pop();
            if(dist[cur] < cost) continue;
            for(auto& [ncost, nxt] : g[cur]){
                if(dist[nxt] > ncost + cost){
                    PQ.push({dist[nxt] = ncost + cost, nxt});
                }
            }
        }
        return dist;
    };
    auto dist = Dijkstra(1);
    int mx = 0;
    for(int i = 1; i <= n; i++) if(dist[i] != INF) mx = max<int>(mx, dist[i] + cost[i]);
    cout << mx << "\n";
    return 0;
}