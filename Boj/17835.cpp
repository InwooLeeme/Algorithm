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

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

using pt = pair<int, int>;

int n,m,p;
const int INF = int(2e18);
vector<pt> G[111'111];

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> p;
    while(m--){
        int a,b,c; cin >> a >> b >> c;
        G[b].push_back({c, a});
    }
    min_heap<pt> PQ;
    vector<int> dist(n + 12, INF);
    for(int i = 0; i < p; i++){
        int s; cin >> s;
        dist[s] = 0;
        PQ.push({dist[s], s});
    }
    // dijkstra
    while(!PQ.empty()){
        auto c = PQ.top(); PQ.pop();
        auto cost = c.first, cur = c.second;
        if(dist[cur] < cost) continue;
        for(auto xt : G[cur]){
            auto ncost = xt.first, nxt = xt.second;
            if(dist[nxt] > ncost + cost) PQ.push({dist[nxt] = ncost + cost, nxt});
        }
    }
    int mx = 0,mxIdx = 0;
    for(int i = 1; i <= n; i++){
        if(dist[i] == INF) continue;
        if(dist[i] > mx){
            mx = dist[i];
            mxIdx = i;
        }
    }
    cout << mxIdx << '\n' << mx << "\n"; 
    return 0; 
}
