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

using pii = pair<int, int>;

int32_t main(){
    fastio;
    int MOD,n,s; cin >> MOD >> n >> s;
    vector<int> dist(1000001, -1);
    vector<pii> v(n);
    for(auto& [a, b] : v) cin >> a >> b;
    queue<int> Q;
    dist[s] = 0;
    Q.push(s);
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        if(!cur){
            cout << dist[cur] << "\n";
            return 0;
        }
        for(auto& [a, b] : v){
            auto nxt = (a*cur + b) % MOD;
            if(nxt < 0 || nxt > 1000000 || dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
        }        
    }
    cout << -1 << "\n";
    return 0;
}