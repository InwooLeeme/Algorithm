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

int n,m,q,r,c;
int board[44][44];
int sticker[12][12];

bool Bound(int x, int y){ return x < 0 or x >= n or y < 0 or y >= m; }

void Rotate(){
    int temp[12][12];
    for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) temp[j][r - 1 - i] = sticker[i][j];
    for(int i = 0; i < c; i++) for(int j = 0; j < r; j++) sticker[i][j] = temp[i][j];
    swap(r, c);
}

bool IsPossible(int x, int y){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(sticker[i][j] and board[i + x][j + y]) return 0;
        }
    }
    for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) if(sticker[i][j]) board[i + x][j + y] = 1;
    return 1;
}

void Main(){
    #define sz(v) (int)(v).size()
    cin >> n >> m >> q;
    for(int k = 0; k < q; k++){
        cin >> r >> c;
        for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) cin >> sticker[i][j];
        int cnt = 4;
        [&](){
            while(cnt--){
                bool isPastable = 0;
                for(int i = 0; i <= n - r; i++){
                    for(int j = 0; j <= m - c; j++){
                        if(IsPossible(i, j)){
                            isPastable = 1;
                            return;
                        }
                    }
                }
                Rotate();
            }
        }();
    }
    int ret = 0;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) ret += board[i][j];
    cout << ret << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}