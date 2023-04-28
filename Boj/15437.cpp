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

int n,m;
bool Bound(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }
string board[222];
bool vist[222][222];

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> board[i];
    int x = 0,y = 0,cnt = 0;
    while(1){
        if(Bound(x, y)){
            cout << "Out" << "\n";
            return 0;
        }
        if(vist[x][y]){
            cout << "Lost" << "\n";
            return 0;
        }
        vist[x][y] = 1;
        if(board[x][y] == 'T'){
            cout << cnt << "\n";
            return 0;
        }
        if(board[x][y] == 'N') x -= 1;
        else if(board[x][y] == 'S') x += 1;
        else if(board[x][y] == 'E') y += 1;
        else if(board[x][y] == 'W') y -= 1;
        cnt++;
    }
    return 0;
}