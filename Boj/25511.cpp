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

vector<int> adj[111111];
int n,k,ret;
int v[111111];

void DFS(int cur, int par, int dep = 0){
    if(v[cur] == k) ret = dep;
    for(auto nxt : adj[cur]){
        if(nxt == par) continue;
        DFS(nxt, cur, dep + 1);
    }
}

int32_t main(){
    fastio;
    cin >> n >> k;
    for(int i = 1; i < n; i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
    }
    for(int i = 0; i < n; i++) cin >> v[i];
    DFS(0, -1, 0);
    cout << ret << "\n";
    return 0;
}