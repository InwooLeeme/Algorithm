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

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

void Main(){
    int n,ret = 0; cin >> n;
    vector<string> v(n); for(auto& i : v) cin >> i;
    auto Bound = [&](int x, int y) -> bool{ return x < 0 or x >= n or y < 0 or y >= n; };
    auto Sol = [&]() -> int{
        int ret = 0;
        vector<vector<int>> vist(n + 1, vector<int>(n + 1));
        auto DFS = [&](int x, int y, auto&& DFS) -> void{
            vist[x][y] = 1;
            for(int d = 0; d < 4; d++){
                auto nx = x + dx[d], ny = y + dy[d];
                if(Bound(nx, ny) or vist[nx][ny] or v[nx][ny] != '.') continue;
                DFS(nx, ny, DFS);
            }
        };
        for(int x = 0; x < n; x++) for(int y = 0; y < n; y++){
            if(!vist[x][y] and v[x][y] == '.'){ ret++; DFS(x, y, DFS); }
        }
        return ret;
    };
    auto Get = [&](int x, int y) -> int{
        for(int d = 0; d < 4; d++){
            auto nx = x + dx[d], ny = y + dy[d];
            if(Bound(nx, ny)) continue;
            if(v[nx][ny] == '.') return 0;
        }
        return 1;
    };
    auto cnt = Sol();
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
        
        if(v[i][j] != '.') continue;
        v[i][j] = '@';
        ret += (cnt != Sol() + Get(i, j) ? 1 : 0);
        v[i][j] = '.';
    }
    cout << ret << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}