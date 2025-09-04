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


void Main(){
    int t; cin >> t;
    while(t--){
        int n,m; cin >> m >> n;
        vector<vector<int>> g(10101);
        for(int i = 0; i < m; i++){
            int a,b; cin >> a >> b;
            g[i].push_back(a);
            if(a != b) g[i].push_back(b);
        }
        vector<int> par(10101, -1),vist(10101);
        auto dfs = [&](int cur, auto&& dfs) -> bool{
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
        for(int i = 0; i < m; i++){
            fill(vist.begin(), vist.end(), 0);
            res += dfs(i, dfs);
        }
        cout << (res == m ? "successful hashing" : "rehash necessary") << "\n";
    }
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}
