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

void Sol(){
    int n,q,id = 1; cin >> n; vector<string> v(n); for(auto& i : v) cin >> i; cin >> q;
    map<string, int> IDX;
    map<int, string> rev; sort(v.begin(), v.end());
    for(auto& i : v) IDX[i] = id,rev[id++] = i;
    vector<int> g[id];
    auto Check = [&](string& a, string& b) -> int{
        int ret = 0;
        for(int i = 0; i < a.size(); i++) ret += (a[i] != b[i]);
        return ret;
    };
    for(auto& u : v){
        for(auto& w : v){
            if(u == w) continue;
            int s = Check(u, w);
            if(s == 1) g[IDX[u]].push_back(IDX[w]);
        }
    }
    while(q--){
        string a, b; cin >> a >> b;
        int s = IDX[a], e = IDX[b];
        queue<int> Q; vector<int> dist(id + 1, -1), par(id + 10);
        Q.push(s); dist[s] = 0;
        while(Q.size()){
            auto cur = Q.front(); Q.pop();
            if(cur == e) break;
            for(auto nxt : g[cur]){
                if(dist[nxt] != -1) continue;
                dist[nxt] = dist[cur] + 1;
                par[nxt] = cur;
                Q.push(nxt);
            }
        }
        if(dist[e] == -1) cout << "No word ladder from "<< a << " to " << b << " using the input dictionary." << "\n";
        else{
            int x = e;
            vector<int> track = {e};
            while(x != s){
                x = par[x];
                track.push_back(x);
            }
            cout << "Word ladder from " << a << " to " << b << ": ";
            for(int i = track.size() - 1; i >= 0; i--) cout << rev[track[i]] << (i != 0 ? " --> " : "");
            cout << "\n";
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    int t; cin >> t; while(t--) Sol();
    return 0;
}