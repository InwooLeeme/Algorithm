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

int n,m,s;
vector<int> g[1 << 17];

void Main(){
    cin >> n >> m >> s;
    set<int> st; st.insert(1); st.insert(n);
    for(int i = 0; i < max<int>(s - 2, 0); i++){
        int x; cin >> x;
        st.insert(x);
    }
    for(register int _ = 0; _ < m; _++){
        int a,b; cin >> a >> b;
        if(st.count(a) and st.count(b)){
            g[a].push_back(b); g[b].push_back(a);
        }
    }
    queue<int> q;
    vector<int> dist(n + 1, -1); dist[1] = 1; q.push(1);
    while(q.size()){
        auto cur = q.front(); q.pop();
        for(const auto& nxt : g[cur]){
            if(dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1; q.push(nxt);
        }
    }
    cout << dist[n] << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}
