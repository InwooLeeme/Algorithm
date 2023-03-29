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

vector<int> g[1111];
int n,k,s,e;

int H(const string& a, const string& b){
    int ret = 0;
    for(int i = 0; i < k; i++) if(a[i] != b[i]) ret++;
    return ret;
}

int32_t main(){
    fastio;
    cin >> n >> k;
    vector<string> v(n);
    for(auto& i : v) cin >> i;
    cin >> s >> e; --s,--e;
    vector<int> par(n + 1),dist(n + 1, -1),path;
    // construct graph
    for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++){
        auto a = v[i],b = v[j];
        int d = H(a, b);
        if(d > 1) continue;
        g[i].push_back(j);
        g[j].push_back(i);
    }
    queue<int> Q;
    dist[s] = 0;
    Q.push(s);
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        if(cur == e) break;
        for(auto nxt : g[cur]){
            if(dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            par[nxt] = cur;
            Q.push(nxt);
        }
    }
    if(dist[e] == -1){
        cout << -1 << "\n";
        return 0;
    }
    int x = e;
    while(x != s){
        path.push_back(x);
        x = par[x];
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    for(auto& i : path) cout << i + 1 << " ";
    return 0;
}