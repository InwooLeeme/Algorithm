# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

int32_t main(){
    for(int tc = 1; ; tc++){
        vector<vector<int>> g(22);
        for(int i = 1; i <= 19; i++){
            int n;
            if(!(cin >> n)) return 0;
            while(n--){
                int x; cin >> x;
                g[x].push_back(i);
                g[i].push_back(x);
            }
        }
        cout << "Test Set #" << tc << "\n";
        int m; cin >> m;
        while(m--){
            int a,b; cin >> a >> b;
            queue<int> Q;
            vector<int> dist(22, -1);
            dist[a] = 0;
            Q.push(a);
            while(Q.size()){
                auto cur = Q.front(); Q.pop();
                if(cur == b){
                    printf("%2d to %2d: %d\n", a, b, dist[b]);
                    break;
                }
                for(auto nxt : g[cur]){
                    if(dist[nxt] != -1) continue;
                    dist[nxt] = dist[cur] + 1;
                    Q.push(nxt);
                }
            }
        }
        cout << "\n";
    }
}
