#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int int_fast64_t
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

vector<int> adj[1111];
int sz[1111];
int n;

void F(int cur, int par){
    sz[cur] = 1;
    for(auto& nxt : adj[cur]){
        if(nxt == par) continue;
        F(nxt, cur);
        sz[cur] += sz[nxt];
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    F(1, -1);
    int mx = 0;
    for(int i = 1; i <= n; i++) mx = max<int>(mx, sz[i] * (n - sz[i]));
    cout << mx << "\n";
}   
