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

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
int n,m,r;
bool vist[111][111];
int board[111][111];

bool Bound(int x, int y){ return x < 0 or x >= n or y < 0 or y >= m; }

void Move(int r, int c, int d){
    using p = pair<int, int>;
    queue<p> Q;
    Q.push({r, c}); vist[r][c] = 1;
    while(Q.size()){
        auto [x, y] = Q.front(); Q.pop();
        int sz = board[x][y];
        for(int k = 0; k < sz; k++){
            auto nx = x + dx[d] * k, ny = y + dy[d] * k;
            if(Bound(nx, ny) or vist[nx][ny]) continue;
            vist[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
}

void Up(int r, int c) { vist[r][c] = 0;}

void Print(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cout << (vist[i][j] ? "F" : "S") << ' ';
        cout << '\n';
    }
}

void Main(){
    int ret = 0;
    cin >> n >> m >> r;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> board[i][j];
    while(r--){
        int a,b,r,c,prv = 0,cur = 0; char d; cin >> a >> b >> d; --a,--b;
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) prv += vist[i][j];
        Move(a, b, string("EWSN").find(d)); cin >> r >> c; --r,--c;
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cur += vist[i][j];
        ret += (cur - prv);
        Up(r, c);
    }
    cout << ret << "\n";
    Print();
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}