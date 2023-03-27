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

using pt = pair<int, int>;
using vs = vector<string>;
using vc = vector<char>;
using vvc = vector<vector<char>>;
using vi = vector<int>;
using vvi = vector<vi>;

struct Game{
    vs board;
    int vist[8][8];
    const int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
    const int dy[8] = {0, 0, -1, 1, 1, -1, 1, -1};
    Game():board(8){
        Init();
    }

    bool Bound(int x, int y) { return x < 0 || x >= 8 || y < 0 || y >= 8; }

    void Init(){
        for(int i = 0; i < 8; i++) cin >> board[i];
    }

    void WallMove(){
        for(int i = 7; i >= 1; i--) board[i] = board[i - 1];
        board[0] = "........";
    }

    bool PlayerMove(){
        vector<pt> v{{7, 0}}, w;
        while(!v.empty()){
            memset(vist, 0, sizeof vist);
            w = v; v.clear();
            for(auto [x, y] : w){
                if(board[x][y] == '#') continue;
                v.push_back({x, y});
                for(int d = 0; d < 8; d++){
                    auto nx = x + dx[d],ny = y + dy[d];
                    if(Bound(nx, ny)) continue;
                    if(vist[nx][ny]++ || board[nx][ny] == '#') continue;
                    v.push_back({nx, ny});
                    if(nx == 0 and ny == 7) return 1;
                }
            }
            WallMove();
        }
        return 0;
    }

    int Sol(){
        return PlayerMove();
    }
};

int32_t main(){
    fastio;
    Game G;
    cout << G.Sol() << "\n";
    return 0;
}