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

using pt = pair<int, int>;
using tii = tuple<int, int, int>;

int dist[2][111'111];

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // input
    int n,k; cin >> n >> k;
    string a,b; cin >> a >> b;
    for(int i = 0; i < n; i++) if(a[i] == '0') dist[0][i] = 1;
    for(int i = 0; i < n; i++) if(b[i] == '0') dist[1][i] = 1;
    cout << [&](){
        queue<tii> Q;
        Q.push({0, 0, 0});
        while(Q.size()){
            auto [x, y, time] = Q.front(); Q.pop();
            if(x < time) continue;
            if(x >= n){
                return 1;
            }
            if(!dist[y][x - 1]){
                dist[y][x - 1] = 1;
                Q.push({x - 1, y, time + 1});
            }
            if(!dist[y][x + 1]){
                dist[y][x + 1] = 1;
                Q.push({x + 1, y, time + 1});
            }
            if(!dist[!y][x + k]){
                dist[!y][x + k] = 1;
                Q.push({x + k, !y, time + 1});
            }
        }
        return 0;
    }() << "\n";
    return 0;
}