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

using pii = pair<int ,int>;

struct Game{
    int n,m;
    vector<vector<int>> board,cloud;
    const int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    const int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

    int F(int x,int MOD){
        return (x % MOD + MOD) % MOD;
    }

    bool OOB(int x,int y){ return x < 0 || x >= n || y < 0 || y >= n; }

    void Init(){
        // Input
        cin >> n >> m;
        board = vector<vector<int>>(n, vector<int>(n, 0));
        cloud = vector<vector<int>>(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> board[i][j];
        cloud[n - 2][0] = cloud[n - 2][1] = 1;
        cloud[n - 1][0] = cloud[n - 1][1] = 1;
    }

    void Set(){
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
            if(cloud[i][j]) cloud[i][j] = 0;
            else if(board[i][j] >= 2){
                board[i][j] -= 2;
                cloud[i][j] = 1;
            }
        }
    }

    void Magic(){
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
            if(!cloud[i][j]) continue;
            int cnt = 0;
            for(int dir = 0; dir < 4; dir++){
                auto nx = i + "2002"[dir] - '1';
                auto ny = j + "0022"[dir] - '1';
                if(OOB(nx, ny) || !board[nx][ny]) continue;
                cnt++;
            }
            board[i][j] += cnt;
        }
    }

    void Rain(){
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) board[i][j] += cloud[i][j];
    }

    void Move(int d,int k){
        static vector<vector<int>> temp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
            temp[F(i + k*dx[d], n)][F(j + k*dy[d], n)] = cloud[i][j];
        }
        cloud = temp;
    }

    int Sol(){
        int ret = 0;
        while(m--){
            int d,k; cin >> d >> k; --d;
            Move(d, k);
            Rain();
            Magic();
            Set();
        }
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) ret += board[i][j];
        return ret;
    }
} G;

int32_t main(){
    fastio;
    G.Init();
    cout << G.Sol() << "\n";
    return 0;
}