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

int32_t main(){
    fastio;
    int T; cin >> T;
    while(T--){
        int N,M,idx = 1; cin >> N >> M; cin.ignore();
        vector<vector<int>> adj;
        adj.resize(N + 1);
        while(M--){
            string a,b; cin >> a >> b;
            int x = stoi(a.substr(1, a.size() - 1)),y = stoi(b.substr(1, b.size() - 1));
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        string str; cin >> str;
        auto st = stoi(str.substr(1, str.size() - 1));
        queue<int> Q;
        vector<int> dist(N + 1, -1);
        dist[st] = 0;
        Q.push(st);
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            for(auto nxt : adj[cur]){
                if(dist[nxt] != -1) continue;
                dist[nxt] = dist[cur] + 1;
                Q.push(nxt);
            }
        }
        int ret = 0;
        for(int i = 1; i <= N; i++) if(dist[i] == 1 || dist[i] == 2) ret++;
        cout << "The number of supervillains in 2-hop neighborhood of "  << str << " is " << ret << "\n";
    }
    return 0;
}