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

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n,m,a,b; cin >> n >> m >> a >> b;
    vector<pt> v(m);
    for(auto& [x, y] : v) cin >> x >> y;
    map<int, int> dist;
    auto Bound = [&](int x) -> bool { return x < 0 || x > 100000; };
    dist[0] = 0;
    queue<int> Q;
    Q.push(0);
    while(Q.size()){
        auto cur = Q.front(); Q.pop();
        if(cur == n) {
            cout << dist[cur] << "\n";
            return 0;
        }
        for(auto& [st, en] : v){
            if(st <= cur and cur <= en) {cur = 0; break;}
        }
        for(auto nxt : {cur + a, cur + b}){
            if(dist.count(nxt) || Bound(nxt)) continue;
            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
        }
    }
    cout << -1 << "\n";
    return 0;
}