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

using pii = pair<int, int>;
using tii = tuple<int, int, int>;

const int PRECISION = 0;
const int INF = int(2e18);

vector<vector<int>> D(50'010, vector<int>(2, INF));

void Sol(){
    int n,m,f,s,e; cin >> n >> m >> f >> s >> e;
    vector<pii> G[n + 1];
    vector<int> B[n + 1];
    while(m--){ int a,b,c; cin >> a >> b >> c; G[a].push_back({c, b}); G[b].push_back({c, a}); }
    while(f--){ int a,b; cin >> a >> b; B[a].push_back(b); }
    priority_queue<tii, vector<tii>, greater<tii>> PQ; 
    PQ.push({D[s][0] = 0, s, 0});
    while(PQ.size()){
        auto [cost, cur, state] = PQ.top(); PQ.pop();
        if(cur == e) break;
        if(D[cur][state] < cost) continue;
        for(auto [ncost, nxt] : G[cur]){
            if(D[nxt][state] > ncost + cost){
                D[nxt][state] = ncost + cost;
                PQ.push({D[nxt][state], nxt, state});
            }
        }
        if(!state){
            for(auto nxt : B[cur]){
                if(D[nxt][1] > cost){
                    PQ.push({D[nxt][1] = cost, nxt, 1});
                }
            }
        }
    }
    cout << min<int>(D[e][0], D[e][1]) << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Sol();
    return 0;
}