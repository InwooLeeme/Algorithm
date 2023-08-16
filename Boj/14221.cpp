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
    int n,m; cin >> n >> m;
    vector<p> G[n + 1];
    while(m--){
        int a,b,c; cin >> a >> b >> c;
        G[a].push_back({c, b}); G[b].push_back({c, a});
    }
    vector<int> dist(n + 1, INF);
    priority_queue<p, vector<p>, greater<>> PQ;
    int k,q; cin >> k >> q;
    vector<int> v(k),w(q); for(auto& i : v) cin >> i; 
    for(auto& i : w) cin >> i, dist[i] = 0, PQ.push({dist[i], i});
    auto Dijkstra = [&]() -> void{
        while(PQ.size()){
            auto [cost, cur] = PQ.top(); PQ.pop();
            if(dist[cur] < cost) continue;
            for(auto [ncost, nxt] : G[cur]){
                if(dist[nxt] > ncost + cost) PQ.push({dist[nxt] = ncost + cost, nxt});                
            }
        }
    };
    Dijkstra();
    int ret = INF,mn = INF;
    for(auto& i : v){
        if(mn > dist[i]) mn = dist[i],ret = i;
        if(mn == dist[i] and ret > i) ret = i;
    }
    cout << ret << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}