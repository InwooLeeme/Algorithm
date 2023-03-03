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

vector<int> adj[66];
bitset<1111> vist;
int n,k,root,ret;

void DFS(int cur){
    vist[cur] = 1;
    if(adj[cur].size() == 0){
        ret++;
        return;
    }
    if(adj[cur].size() == 1 and adj[cur][0] == k){
        ret++;
        return;
    }
    for(auto nxt : adj[cur]){
        if(vist[nxt] || nxt == k) continue;
        DFS(nxt);
    }
}

int32_t main(){
    fastio;
    cin >> n;
    for(int i = 0,t; i < n; i++){
        cin >> t;
        if(t == -1) {root = i; continue;}
        adj[t].push_back(i);
    }
    cin >> k;
    if(root != k) DFS(root);
    cout << ret << "\n";
    return 0;
}