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

const int kdx[8] = {2, 1, 2, 1, -1, -2, -2, -1};
const int kdy[8] = {1, 2, -1, -2, 2, 1, -1, -2};
vector<vector<int>> dist(444, vector<int>(444, -1));
int D[444][444];
int n,m;
constexpr int MOD = 1e9 + 9;

bool OOB(int x,int y) { return x < 1 || x > n || y < 1 || y > m; }

int32_t main(){
    fastio;
    cin >> n >> m;
    queue<pii> Q;
    dist[1][1] = 0;
    D[1][1] = 1;
    Q.push({1, 1});
    while(!Q.empty()){
        auto [curX, curY] = Q.front(); Q.pop();
        for(int dir = 0; dir < 8; dir++){
            auto nx = curX + kdx[dir],ny = curY + kdy[dir];
            if(OOB(nx, ny)) continue;
            if(dist[nx][ny] == -1){
                dist[nx][ny] = dist[curX][curY] + 1;
                Q.push({nx, ny});
                D[nx][ny] = D[curX][curY];
            }
            else if(dist[nx][ny] == dist[curX][curY] + 1) (D[nx][ny] += D[curX][curY]) %= MOD;
        }
    }
    if(dist[n][m] == -1) cout << "None" << "\n";
    else cout << dist[n][m] << ' ' << D[n][m] << "\n";
    return 0;
}