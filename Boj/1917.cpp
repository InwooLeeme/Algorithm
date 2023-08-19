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

using vi = vector<int>;
using vvi = vector<vi>;
int n = 6;

vvi chk1{
    {1, 0, 0, 0},
    {1, 1, 1, 1},
    {1, 0, 0, 0}
};

vvi chk2{
    {1, 0, 0 ,0},
    {1, 1, 1, 1},
    {0, 1, 0, 0}
};

vvi chk3{
    {1, 0, 0, 0},
    {1, 1, 1, 1},
    {0, 0, 1, 0}
};

vvi chk4{
    {1, 0, 0, 0},
    {1, 1, 1, 1},
    {0, 0, 0, 1}
};

vvi chk5{
    {0, 1, 0, 0},
    {1, 1, 1, 1},
    {0, 1, 0, 0}
};

vvi chk6{
    {0, 1, 0, 0},
    {1, 1, 1, 1},
    {0, 0, 1, 0}
};

vvi chk7{
    {1, 0, 0, 0},
    {1, 1, 1, 0},
    {0, 0, 1, 1}
};

vvi chk8{
    {0, 1, 0, 0},
    {1, 1, 1, 0},
    {0, 0, 1, 1}
};

vvi chk9{
    {0, 0, 1, 0},
    {1, 1, 1, 0},
    {0, 0, 1, 1}
};

vvi chk10{
    {1, 1, 1, 0, 0},
    {0, 0, 1, 1, 1}
};

vvi chk11{
    {1, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 1, 1}
};

vvi Rotate(vvi& v){
    vvi ret(n, vi(n));
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) ret[i][j] = v[j][n - 1 - i];
    return ret;
}

vvi Flip(vvi& v){
    vvi ret(n, vi(n));
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) ret[i][j] = v[i][n - 1 - j];
    return ret;
}

void Print(vvi& v){
    for(auto& i : v){
        for(auto& j : i) cout << j << " ";
        cout << "\n";
    }
}

/* for 3 x 4 board */
bool Sol1(vvi& board, vvi& chk){
    for(int x = 0; x <= n - 3; x++) for(int y = 0; y <= n - 4; y++){
        bool flag = 1;
        for(int i = 0; i < 3; i++) for(int j = 0; j < 4; j++){
            if(chk[i][j] ^ board[i + x][j + y]) flag = 0;
        }
        if(flag) return 1;
    }
    return 0;
}

/* for 2 x 5 board*/
bool Sol2(vvi& board, vvi& chk){
    for(int x = 0; x <= n - 2; x++) for(int y = 0; y <= n - 5; y++){
        bool flag = 1;
        for(int i = 0; i < 2; i++) for(int j = 0; j < 5; j++){
            if(chk[i][j] ^ board[i + x][j + y]) flag = 0;
        }
        if(flag) return 1;
    }
    return 0;
}   

void Main(){
    int N = 3;
    while(N--){
        vvi board(n, vi(n));
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> board[i][j];
        bool flag = 0;
        for(int d = 0; d < 8; d++){
            if(d == 4) board = Flip(board);
            if(Sol1(board, chk1)){flag = 1; break;}
            if(Sol1(board, chk2)){flag = 1; break;}
            if(Sol1(board, chk3)){flag = 1; break;}
            if(Sol1(board, chk4)){flag = 1; break;}
            if(Sol1(board, chk5)){flag = 1; break;}
            if(Sol1(board, chk6)){flag = 1; break;}
            if(Sol1(board, chk7)){flag = 1; break;}
            if(Sol1(board, chk8)){flag = 1; break;}
            if(Sol1(board, chk9)){flag = 1; break;}
            if(Sol1(board, chk11)){flag = 1; break;}
            if(Sol2(board, chk10)) {flag = 1; break;}
            board = Rotate(board);
        }
        cout << (flag ? "yes" : "no") << "\n";
    }    
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}