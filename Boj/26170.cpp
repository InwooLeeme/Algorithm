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

int v[11][11];
bool vist[11][11];
int ret = -1,mn = int(2e9);
bool Bound(int x, int y){ return x < 0 or x >= 5 or y < 0 or y >= 5; }
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

void f(int dep, int apple, int x, int y){
    if(apple == 3){
        ret = 1;
        mn = min<int>(mn, dep);
        return;
    }
    for(int d = 0; d < 4; d++){
        auto nx = x + dx[d], ny = y + dy[d];
        if(Bound(nx, ny) or vist[nx][ny] or v[nx][ny] == -1) continue;
        vist[nx][ny] = 1;
        f(dep + 1, apple + (v[nx][ny] == 1 ? 1 : 0), nx, ny);
        vist[nx][ny] = 0;
    }
}

void Main(){
    for(int i = 0; i < 5; i++) for(int j = 0; j < 5; j++) cin >> v[i][j];
    int r,c; cin >> r >> c; vist[r][c] = 1;
    f(0, v[r][c] == 1 ? 1 : 0, r, c);
    cout << (ret == -1 ? -1 : mn) << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}