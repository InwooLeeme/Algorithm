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

struct Game{
    int n,k;
    bool red,blue;
    vector<string> board;
    Game(int n, int k):n(n),k(k),board(n),red(0),blue(0){};
    void Input(){
        for(auto& i : board) cin >> i;
    }
    vector<string> ResetBoard(){
        vector<string> ret;
        for(int i = 0; i < n; i++){
            string s = "";
            for(int j = 0; j < n; j++) s.push_back('.');
            ret.push_back(s);
        } 
        return ret;
    };

    bool Check(char c){
        using p = pair<int, int>;
        const int dx[4] = {1, 0, 1, 1};
        const int dy[4] = {0, 1, 1, -1};
        for(int d = 0; d < 4; d++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(board[i][j] != c) continue;
                    int cnt = 1;
                    queue<p> Q;
                    Q.push({i, j});
                    while(Q.size()){
                        auto [x, y] = Q.front(); Q.pop();
                        auto nx = x + dx[d], ny = y + dy[d];
                        if(nx < 0 or nx >= n or ny < 0 or ny >= n) continue;
                        if(board[nx][ny] != c) continue;
                        cnt++;
                        Q.push({nx, ny});
                    }
                    if(cnt >= k) return 1;
                }
            }
        }
        return 0;
    };

    bool Bound(int y){ return y < 0 or y >= n; };

    void Gravity(){
        for(int j = 0; j < n; j++) for(int i = n - 1; i >= 0; i--){
            int temp = i - 1;
            while(board[i][j] == '.' and temp >= 0) swap(board[i][j], board[temp--][j]);
        }
    };

    void Print(vector<string>& v){
        for(auto& i : v) cout << i << "\n";
    }

    vector<string> Rotate(){
        auto ret = ResetBoard();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) ret[i][j] = board[n - 1 - j][i];
        }
        return ret;
    };

    string Sol(){
        board = Rotate(); 
        Gravity();
        red = Check('R'), blue = Check('B');
        if(red and blue) return "Both";
        else if(red and !blue) return "Red";
        else if(!red and blue) return "Blue";
        return "Neither";
    };
};

void Main(){
    int t; cin >> t; for(int tc = 1; tc <= t; tc++){
        int n,k; cin >> n >> k;
        Game G(n, k);
        G.Input();
        cout << "Case #" << tc << ": " << G.Sol() << "\n";
    }
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}