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

using vi = vector<int>;
using vvi = vector<vi>;

constexpr int INF = int(2e9);


int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t;
    for(int tc = 1; tc <= t; tc++){
        cout << "DATA SET " << tc << "\n\n";
        int n,m,p; cin >> n >> m >> p;
        map<string, int> M;
        for(int i = 1; i <= n; i++){
            string s; cin >> s;
            M[s] = i;
        }
        vvi dist(n + 1, vi(n + 1, INF));
        while(m--){
            string a,b; cin >> a >> b;
            dist[M[a]][M[b]] = dist[M[b]][M[a]] = 1;
        }
        // floyd
        for(int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++){
            dist[i][j] = min<int>(dist[i][j], dist[i][k] + dist[k][j]);
        }
        while(p--){
            int r;
            string a,b; cin >> r >> a >> b;
            int ret = dist[M[a]][M[b]];
            if(ret == INF) cout << "NO SHIPMENT POSSIBLE" << '\n';
            else{
                cout << "$" << ret * r * 100 << "\n";
            }
        }
        cout << '\n';
    }
    return 0;
}