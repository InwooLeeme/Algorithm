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

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
const int ddx[8] = {0, 0, 1, 1, 1, -1, -1, -1}, ddy[8] = {1, -1, 1, 0, -1, 1, 0, -1};

void Sol(){
    int n,m,q; cin >> n >> m; cin.ignore();
    vector<string> v(n);
    for(auto& i : v) cin >> i;
    cin >> q;
    while(q--){
        char c; cin >> c;
        if(c == 'M'){
            int x,y,z; cin >> x >> y >> z;
            v[x][y] = (z == 1 ? '1' : '0');
        }
        else{
            int ret = 0;
            vector<vector<bool>> vist(n,vector<bool>(m, 0));
            function<void(int, int)> DFS = [&](int x,int y) -> void{
                vist[x][y] = 1;
                for(int dir = 0; dir < 4; dir++){
                    auto nx = x + dx[dir],ny = y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(vist[nx][ny] || v[nx][ny] == '0') continue;
                    DFS(nx, ny);
                }
            };
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(!vist[i][j] and v[i][j] == '1'){
                        DFS(i, j);
                        ret++;
                    }
                }
            }
            cout << ret << "\n";
        }
    }
}

int32_t main(){
    fastio;
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++){
        cout << "Case #" << tc <<": \n";
        Sol();
    }
    return 0;
}