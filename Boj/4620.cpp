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

const int dx[2] = {1, 0};
const int dy[2] = {0, 1};

using vi = vector<int>;
using vvi = vector<vi>;

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; 
    while(cin >> n and n != -1){
        vector<string> board(n);
        vvi D(n + 1, vi(n + 1, -1));
        for(auto& i : board) cin >> i;
        auto Bound = [&](int x, int y) -> bool { return x < 0 || x >= n || y < 0 || y >= n; };
        auto Sol = [&](int x, int y, auto&& Sol) -> int{
            if(x == n - 1 and y == n - 1) return 1;
            int& ret = D[x][y];
            if(ret != -1) return ret;
            ret = 0;
            for(int d = 0; d < 2; d++){
                auto nx = x + dx[d] * (board[x][y] - '0'), ny = y + dy[d] * (board[x][y] - '0');
                if(Bound(nx, ny)) continue;
                ret += Sol(nx, ny, Sol);
            }
            return ret;
        };
        cout << Sol(0, 0, Sol) << "\n";
    }
    return 0;
}