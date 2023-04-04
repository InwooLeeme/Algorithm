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

using vi = vector<int>;

char board[11][11];

int32_t main(){
    fastio;
    int n,m,c; cin >> n >> m >> c;
    vi v; 
    for(int i = 1,t; i <= c; i++){
        cin >> t;
        for(int j = 0; j < t; j++) v.push_back(i);
    }
    int dir = 1,t = 0;
    for(int i = 0; i < n; i++, dir *= -1){
        for(int j = (dir == 1 ? 0 : m - 1); (dir == 1 ? (j < m) : (j >= 0)); j += dir){
            board[i][j] = char(v[t++] + '0');
        }
    }
    for(int i = 0; i < n; i++){
        cout << board[i];
        cout << '\n';
    }
    return 0;   
}