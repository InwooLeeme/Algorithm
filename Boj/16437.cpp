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

#define int int64_t

vector<int> adj[123477];
vector<int> v(123477);
vector<bool> chk(123477, 0);
int n;

int DFS(int cur,int par){
    int ret = 0;
    for(auto nxt : adj[cur]){
        if(nxt == par) continue;
        ret += DFS(nxt, cur);
    }
    if(chk[cur]) return (ret > v[cur] ? ret - v[cur] : 0);
    return ret + v[cur];
}

int32_t main(){
    fastio;
    cin >> n;
    for(int i = 2; i <= n; i++){
        char t;
        int ai,pi; cin >> t >> ai >> pi;
        if(t == 'W') chk[i] = 1;
        v[i] = ai;
        adj[i].push_back(pi);
        adj[pi].push_back(i);
    }
    cout << DFS(1, 0) << "\n";
    return 0;
}