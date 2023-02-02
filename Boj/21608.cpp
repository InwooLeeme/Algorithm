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

//#define int int_fast64_t

struct Game{
    int n;
    int board[21][21];
    int Info[444][444];
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0, -1};
    queue<int> Q;

    bool OOB(int x,int y) { return x < 0 || x >= n || y < 0 || y >= n; }

    void Init(){
        cin >> n;
        for(int i = 0,t; i < n * n; i++){
            cin >> t;
            Q.push(t);
            for(int j = 0,t2; j < 4; j++){
                cin >> t2; Info[t][t2] = 1;
            }
        }
    }   

    void Sol(){
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            int x = 0,y = 0,t1 = -1,t2 = -1;
            for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
                if(board[i][j]) continue;
                int t3 = 0,t4 = 0;
                for(int dir = 0; dir < 4; dir++){
                    auto nx = i + dx[dir],ny = j + dy[dir];
                    if(OOB(nx, ny)) continue;
                    if(!board[nx][ny]) t3++;
                    if(Info[cur][board[nx][ny]]) t4++;
                }
                if(t1 < t4 || t1 == t4 && t2 < t3){
                    t1 = t4;
                    t2 = t3;
                    x = i,y = j;
                }
            }
            board[x][y] = cur;
        }
    }

    int GetScore(){
        int score = 0;
        int DB[5] = {0, 1, 10, 100, 1000};
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
            int cnt = 0;
            for(int dir = 0; dir < 4; dir++){
                auto nx = i + dx[dir],ny = j + dy[dir];
                if(OOB(nx, ny)) continue;
                cnt += Info[board[i][j]][board[nx][ny]];
            }
            score += DB[cnt];
        }
        return score;
    }
} G;

int32_t main(){
    fastio;
    G.Init();
    G.Sol();
    cout << G.GetScore() << "\n";
    return 0;
}