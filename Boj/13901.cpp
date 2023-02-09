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

bool vist[1111][1111];
int n,m,k;

bool OOB(int x,int y){ return x < 0 || x >= n || y < 0 || y >= m; }

int32_t main(){
    fastio;
    cin >> n >> m >> k;
    while(k--){
        int a,b; cin >> a >> b;
        vist[a][b] = 1;
    }
    vector<int> v(4);
    int x,y; cin >> x >> y;
    for(int i = 0; i < 4; i++) cin >> v[i],--v[i];
    vist[x][y] = 1;
    for(int d = 0,cnt = 0; cnt < 4; d = (d + 1) % 4){
        int nx = x,ny = y;
        int dx = "0211"[v[d]] - '1';
        int dy = "1102"[v[d]] - '1';
        while(!OOB(x + dx,y + dy) and !vist[x + dx][y + dy]) vist[x += dx][y += dy] = 1;
        if(x == nx and y == ny) cnt++;
        else cnt = 0;
    }
    cout << x << ' ' << y << "\n";
    return 0;
}