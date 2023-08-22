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

int board[22][22], board2[22][22];
int n;

void Rotate(){
    int temp[22][22];
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) temp[i][j] = board2[n - j - 1][i];
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) board2[i][j] = temp[i][j];
}

void Slide(int dir){
    while(dir--) Rotate();
    for(int i = 0; i < n; i++){
        vector<int> merged(22);
        int idx = 0;
        for(int j = 0; j < n; j++){ 
            if(!board2[i][j]) continue;
            if(merged[idx] == 0) merged[idx] = board2[i][j];
            else if(merged[idx] == board2[i][j]) merged[idx++] <<= 1;
            else merged[++idx] = board2[i][j];            
        }
        for(int j = 0; j < n; j++) board2[i][j] = merged[j];
    }
}


void Main(){
    cin >> n;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> board[i][j];
    int mx = 0;
    const int sz = 1 << (2 * 5);
    for(int temp = 0; temp < sz; temp++){
        int brute = temp;
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) board2[i][j] = board[i][j];
        for(int i = 0; i < 5; i++){
            Slide(brute % 4);
            brute /= 4;
        }
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) mx = max<int>(mx, board2[i][j]);
    }
    cout << mx << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}