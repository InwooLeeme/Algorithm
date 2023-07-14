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
using vi = vector<int>;
using vvi = vector<vi>;

const int INF = int(2e9);

void Sol(){
    vector<pt> g[2555];
    int n; cin >> n;
    vector<pt> w(n + 2);
    for(int i = 0; i < n + 2; i++) cin >> w[i].first >> w[i].second;
    // graph construct
    for(int i = 0; i < n + 2; i++){
        for(int j = i + 1; j < n + 2; j++){
            g[i].push_back({abs(w[i].first - w[j].first) + abs(w[i].second - w[j].second), j});
            g[j].push_back({abs(w[i].first - w[j].first) + abs(w[i].second - w[j].second), i});
        }
    }
    vector<int> dist(2555, INF);
    // dijkstra
    priority_queue<pt, vector<pt>, greater<>> PQ;
    PQ.push({dist[0] = 0, 0});
    while(PQ.size()){
        auto [cost, cur] = PQ.top(); PQ.pop();
        if(dist[cur] < cost) continue;
        for(auto [ncost, nxt] : g[cur]){
            if(ncost > 50*20) continue;
            if(dist[nxt] > ncost + cost){
                dist[nxt] = ncost + cost;
                PQ.push({dist[nxt], nxt});
            }
        }
    }
    if(dist[n + 1] == INF) cout << "sad" << '\n';
    else cout << "happy" << '\n';
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while(t--) Sol();
    return 0;
}