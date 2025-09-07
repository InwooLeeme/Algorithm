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

int n,m,k;
constexpr int INF = int(2e18);

void Main(){
    while(cin >> n >> m >> k and n){
        vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
        for(int i = 0; i < m; i++){
            int a,b,c; cin >> a >> b >> c;
            dist[a][b] = dist[b][a] = c;
        }
        for(int i = 0; i < n; i++) dist[i][i] = 0;
        for(int k = 0; k < n; k++) for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
            dist[i][j] = min<int>(dist[i][j], dist[i][k] + dist[k][j]);
        }
        vector<vector<int>> g(k + 1);
        vector<int> vist(k + 1), par(k + 1, -1);
        vector<pair<int, int>> v(k);
        for(auto& [a, b] : v) cin >> a >> b;
        sort(v.begin(), v.end(), [&](auto& a, auto& b){
            return a.second < b.second;
        });
        for(int i = 0; i < k; i++){
            auto [a, ta] = v[i];
            for(int j = i + 1; j < k; j++){
                auto [b, tb] = v[j];
                if(dist[a][b] <= (tb - ta) or (ta == tb and a == b)) g[i].push_back(j);
            }
        }
        auto dfs = [&](int cur, auto&& dfs) -> int{
            for(const auto& nxt : g[cur]){
                if(vist[nxt]) continue;
                vist[nxt] = 1;
                if(par[nxt] == -1 or dfs(par[nxt], dfs)){
                    par[nxt] = cur;
                    return 1;
                }
            }
            return 0;
        };
        int res = 0;
        for(int i = 0; i < k; i++){
            fill(vist.begin(), vist.end(), 0);
            res += dfs(i, dfs);
        }
        cout << k - res << "\n";
    }
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}
