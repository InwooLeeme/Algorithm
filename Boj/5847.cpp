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

vector<int> adj[11111];
int indegree[11111];
int d[11111];

int32_t main(){
    fastio;
    int n,m; cin >> n >> m;
    vector<int> T(n + 1);
    for(int i = 1; i <= n; i++) cin >> T[i];
    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    queue<int> Q;
    for(int i = 1; i <= n; i++){
        if(!indegree[i]){
            Q.push(i);
            d[i] = T[i];
        }
    }
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(auto nxt : adj[cur]){
            if(d[cur] + T[nxt] > d[nxt]) d[nxt] = d[cur] + T[nxt];
            indegree[nxt]--;
            if(!indegree[nxt]) Q.push(nxt);
        }
    }
    int mx = 0;
    for(int i = 1; i <= n; i++) mx = max<int>(mx, d[i]);
    cout << mx << "\n";
    return 0;
}