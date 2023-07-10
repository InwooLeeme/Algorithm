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

using pii = pair<int, int>;

int k,n;
vector<pii> g[11111];
bool Bound(int x){ return x < 0 or x > n; }

vector<int> Dijkstra(int st){
    vector<int> dist(11111, int(2e18));
    priority_queue<pii,vector<pii>, greater<pii>> PQ;
    PQ.push({dist[st] = 0, st});
    while(PQ.size()){
        auto [cost, cur] = PQ.top(); PQ.pop();
        if(dist[cur] < cost) continue;
        if(dist[cur + 1] > cost + 1 and !Bound(cur + 1)){
            dist[cur + 1] = dist[cur] + 1;
            PQ.push({dist[cur + 1], cur + 1});
        }
        for(auto [ncost, nxt] : g[cur]){
            if(dist[nxt] > ncost + cost){
                PQ.push({dist[nxt] = ncost + cost, nxt});
            }
        }
    } 
    return dist;
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> k >> n;
    while(k--){
        int a,b,c; cin >> a >> b >> c;
        g[a].push_back({c, b});
    }
    auto ret = Dijkstra(0);
    cout << ret[n] << "\n";
    return 0;
}