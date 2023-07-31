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

const int PRECISION = 0;

int n;

void Sol(){
    vector<int> G[n + 10];
    map<int, string> Name;
    struct Query {int st, v1, v2; string a,b,c;};
    // input
    for(int i = 1; i <= n; i++){
        int x; while(cin >> x and x){ G[i].push_back(x); }
    }
    vector<Query> Q;
    int q; while(cin >> q and q){
        int t1,t2; string a,b,c; cin >> t1 >> t2 >> a >> b >> c;
        Q.push_back({q, t1, t2, a, b, c});
    }
    for(int i = 1; i <= n; i++){ string s; cin >> s; Name[i] = s; }
    // End of Input
    map<int, vector<string>> ret;
    vector<int> cnt(n + 10);
    for(auto& [st, v1, v2, a, b, c] : Q){
        queue<int> Q; Q.push(st); vector<int> dist(n + 2, -1); dist[st] = 0; 
        while(Q.size()){
            auto cur = Q.front(); Q.pop();
            for(auto nxt : G[cur]){
                if(dist[nxt] != -1) continue;
                dist[nxt] = dist[cur] + 1; Q.push(nxt);
            }
        }
        for(int i = 1; i <= n; i++){
            cnt[i] = G[i].size();
            if(dist[i] == -1) {ret[i].push_back(a); continue;}
            if(cnt[i] < v1) ret[i].push_back(a);
            else if(v1 <= cnt[i] and cnt[i] < v2) ret[i].push_back(b);
            else if(cnt[i] >= v2) ret[i].push_back(c);
        }
    }
    for(auto& [a, b] : ret){
        cout << Name[a] << ": ";
        for(auto& j : b) cout << j << " ";
        cout << "\n";
    }
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    while(cin >> n and n) Sol();
    return 0;
}