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
    int N,tc = 1;
    while(cin >> N and N){ cin.ignore();
        map<string, int> M;
        int idx = 1,ret = 0;
        vector<bool> vist(44, 0);
        vector<vector<int>> adj;
        adj.resize(44);        
        for(int i = 0; i < N; i++){
            string a,b; cin >> a >> b;
            if(!M.count(a)) M[a] = idx++;
            if(!M.count(b)) M[b] = idx++;
            adj[M[a]].push_back(M[b]);
        }
        function<void(int)> DFS = [&](int cur) -> void{
            vist[cur] = 1;
            for(auto nxt : adj[cur]){
                if(vist[nxt]) continue;
                DFS(nxt);
            }
        };
        for(int i = 1; i < idx; i++){
            if(!vist[i]){
                DFS(i);
                ret++;
            }
        }
        cout << tc << " " << ret << "\n";
        tc++;
    }
    return 0;
}