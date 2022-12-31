#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#define int int_fast64_t

using pii = pair<int, int>;

int32_t main(){
    fastio;
    int n,m,q; cin >> n >> m >> q;
    vector<vector<int>> board(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) cin >> board[i][j];
    int cnt = 0;
    vector<pii> v(q);
    for(auto& [a, b] : v) cin >> a >> b;
    for(int i = 1; i <= n; i++){
        bool check = 0;
        for(auto& [a, b] : v){
            if(board[i][a] == b) continue;
            check = 1;
        }
        if(!check) cnt++;
    }
    cout << cnt << "\n";
    return 0;
}