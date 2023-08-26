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

const int PRECISION = 0;

void Main(){
    using p = pair<int, int>;
    constexpr int INF = int(2e18);
    int n,m,a,b,c; cin >> n >> a >> b >> c >> m;
    vector<p> G[n + 1];
    while(m--){
        int u,v,w; cin >> u >> v >> w;
        G[u].push_back({w, v}); G[v].push_back({w, u});
    }
    auto Dijkstra = [&](int st) -> vector<int>{
        vector<int> dist(n + 1, INF);
        priority_queue<p, vector<p>, greater<p>> PQ;
        PQ.push({dist[st] = 0, st});
        while(PQ.size()){
            auto [cost, cur] = PQ.top(); PQ.pop();
            if(dist[cur] < cost) continue;
            for(auto [ncost, nxt] : G[cur]){
                if(dist[nxt] > ncost + cost) PQ.push({dist[nxt] = ncost + cost, nxt});
            }
        }
        return dist;
    };
    auto dista = Dijkstra(a),distb = Dijkstra(b), distc = Dijkstra(c);
    vector<p> ret;
    for(int i = 1; i <= n; i++){
        if(i != a and i != b and i != c and dista[i] != INF and distb[i] != INF and distc[i] != INF){
            int mn = min<int>({dista[i], distb[i], distc[i]});
            ret.push_back({mn, i});
        }
    }
    sort(ret.begin(), ret.end(), [&](p& a, p& b){
        return (a.first == b.first ? a.second < b.second : a.first > b.first);
    });
    cout << ret[0].second << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}