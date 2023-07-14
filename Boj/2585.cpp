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

int n,k;
vector<pt> g[1111];

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    vector<pt> v(n + 2);
    v[0] = {0, 0};
    for(int i = 1; i <= n; i++) cin >> v[i].first >> v[i].second;
    v[n + 1] = {10000, 10000};
    auto f = [&](pt& a, pt& b) -> int{
        return (int)ceil(hypot(a.first - b.first, a.second - b.second) / 10);
    };
    // graph construct
    for(int i = 0; i < v.size(); i++){
        for(int j = i + 1; j < v.size(); j++){
            g[i].push_back({f(v[i], v[j]), j});
            g[j].push_back({f(v[i], v[j]), i});
        }
    }
    auto Check = [&](const int mid) -> bool{
        queue<int> Q;
        vector<int> dist(n + 10, -1);
        dist[0] = 0;
        Q.push(0);
        while(Q.size()){
            auto cur = Q.front(); Q.pop();
            if(cur == n + 1) break;
            for(auto [ncost, nxt] : g[cur]){
                if(ncost > mid) continue;
                if(dist[nxt] != -1) continue;
                dist[nxt] = dist[cur] + 1;
                Q.push(nxt);
            }
        }
        return (dist[n + 1] != -1 and (dist[n + 1] <= k + 1));
    };
    int lo = 0, hi = int(1e18);
    while(lo + 1 < hi){
        int mid = lo + hi >> 1;
        if(!Check(mid)) lo = mid;
        else hi = mid;
    }
    cout << hi << '\n';
    return 0;
}