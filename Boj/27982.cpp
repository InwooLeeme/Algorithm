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

using tii = tuple<int, int, int>;

const int dx[6] = {1, -1, 0, 0, 0 ,0};
const int dy[6] = {0, 0, 1, -1, 0, 0};
const int dz[6] = {0, 0, 0, 0, 1, -1};

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n,m,ret = 0; cin >> n >> m;
    if(m < 6) { cout << 0 << '\n'; return 0; }
    vector<tii> v(m);
    for(auto& [a, b, c] : v) cin >> a >> b >> c;
    for(auto& [x, y, z] : v){
        int cnt = 0;
        for(int d = 0; d < 6; d++){
            auto nx = x + dx[d], ny = y + dy[d], nz = z + dz[d];
            bool flag = 0;
            for(auto& [cx, cy, cz] : v){
                if(nx == cx and cy == ny and cz == nz){ flag = 1; break; }
            }
            cnt += flag;
        }
        if(cnt == 6) ret++;
    }
    cout << ret << '\n';
    return 0;
}