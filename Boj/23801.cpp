# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
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

int n,m,p;
vector<pt> G[100011];

vector<int> Dijkstra(int st){
    priority_queue<pt, vector<pt>, greater<pt>> PQ;
    vector<int> dist(n + 1, INF);
    dist[st] = 0;
    PQ.push({dist[st], st});
    while(PQ.size()){
        auto c = PQ.top(); PQ.pop();
        auto cost = c.first, cur = c.second;
        if(dist[cur] < cost) continue;
        for(auto node : G[cur]){
            auto ncost = node.first, nxt = node.second;
            if(dist[nxt] > ncost + cost){
                dist[nxt] = ncost + cost;
                PQ.push({dist[nxt], nxt});
            }
        }
    }
    return dist;
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
    while(m--){
        int a,b,c; cin >> a >> b >> c;
        G[a].push_back({c, b});
        G[b].push_back({c, a});
    }
    int st,en; cin >> st >> en >> p;
    vector<int> P(p);
    for(auto&  i : P) cin >> i;
    auto dist = Dijkstra(st);
    auto revdist = Dijkstra(en);
    int mn = INF;
    for(auto& i : P){
        if(dist[i] == INF or revdist[i] == INF) continue;
        mn = min<int>(mn, dist[i] + revdist[i]);
    }
    cout << (mn == INF ? -1 : mn) << '\n';
    return 0; 
}
