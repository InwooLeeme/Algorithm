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
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

using pii = pair<int,int>;

vector<pii> adj[1000001];
constexpr int MOD = 1e9 + 9;
constexpr int INF = 1e18;
int n,m;
vector<int> D(1000001);

vector<int> Dijkstra(int st){
    vector<int> dist(n + 1, INF);
    min_heap<pii> PQ;
    dist[st] = 0;
    D[st] = 1;
    PQ.push({dist[st], st});
    while(!PQ.empty()){
        auto [cost, cur] = PQ.top(); PQ.pop();
        if(dist[cur] < cost) continue;
        for(auto [ncost, nxt] : adj[cur]){
            if(dist[nxt] > ncost + cost){
                D[nxt] = D[cur];
                dist[nxt] = ncost + cost;
                PQ.push({dist[nxt], nxt});
            }
            else if(dist[nxt] == ncost + cost){
                (D[nxt] += D[cur]) %= MOD;
            }
        }
    }
    return dist;
}

int32_t main(){
    fastio;
    int s,e;
    cin >> n >> m >> s >> e;
    while(m--){
        int a,b,c; cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    auto dist = Dijkstra(s);
    cout << D[e] << "\n";
    return 0;
}