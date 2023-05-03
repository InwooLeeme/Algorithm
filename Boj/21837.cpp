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

vector<string> Split(string& s){
    vector<string> ret;
    string temp;
    stringstream in(s);
    while(in >> temp) ret.push_back(temp);
    return ret;
}

vector<int> g[333];

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n,idx = 0; cin >> n; cin.ignore();
    map<string, int> M;
    map<int, string> revM;
    string st;
    set<string> order;
    for(int i = 0; i < n; i++){
        string s; getline(cin, s);
        auto ss = Split(s);
        if(!i) st = ss[0];
        vector<string> de;
        order.insert(ss[0]);
        if(!M.count(ss[0])) M[ss[0]] = idx++, revM[idx - 1] = ss[0];
        for(int i = ss.size() - 1; i >= 0; i--){
            auto c = ss[i];
            if(isupper(c[0]) and c != ss[0]) de.push_back(c);
        }
        for(auto& c : de){
            if(!M.count(c)) M[c] = idx++, revM[idx - 1] = c;
            g[M[c]].push_back(M[ss[0]]);
            order.insert(c);
        }
    }
    vector<int> dist(idx, -1);
    queue<int> Q;
    dist[M[st]] = 1;
    Q.push(M[st]);
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(auto nxt : g[cur]){
            if(dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
        }
    }
    for(auto& c : order) cout << (dist[M[c]] == -1 ? 0 : dist[M[c]]) << "\n";
    return 0;
}