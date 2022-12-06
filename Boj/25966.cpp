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

#define int int64_t

int board[3022][3022];

int32_t main(){
    fastio;
    int n,m,q; cin >> n >> m >> q;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> board[i][j];
    vector<int> B(n);
    iota(B.begin(), B.end(), 0);
    while(q--){
        int t,x,y; cin >> t >> x >> y;
        if(!t){
            int k; cin >> k;
            board[B[x]][y] = k;
        }
        else{
            swap(B[x], B[y]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << board[B[i]][j] << ' ';
        }
        cout << "\n";
    }
    return 0;
}