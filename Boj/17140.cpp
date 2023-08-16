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

#define sz(v) (int)v.size()
using vi = vector<int>; using vvi = vector<vi>;
const int mx = 100;
int board[111][111];
int n = 3,m = 3;

int SortRow(int r, vvi& ret){
    vi S;
    map<int, int> M;
    for(int i = 0; i < m; i++){
        if(!board[r][i]) continue;
        M[board[r][i]]++;
        S.push_back(board[r][i]);
    }
    sort(S.begin(), S.end()); S.erase(unique(S.begin(), S.end()), S.end());
    sort(S.begin(), S.end(), [&](int& a, int& b){
        return M[a] == M[b] ? a < b : M[a] < M[b];
    });
    for(int i = 0,l = 0; i < sz(S); i++, l += 2){
        ret[r][l] = S[i];
        ret[r][l + 1] = M[S[i]];
    }
    return (sz(S) << 1);
}

void R(){
    vvi ret(101, vi(101));
    int mx = 0;
    for(int i = 0; i < n; i++){
        auto v = SortRow(i, ret);
        mx = max<int>(mx, v);
    }
    for(int i = 0; i < 101; i++) for(int j = 0; j < 101; j++) board[i][j] = ret[i][j];
    m = min<int>(101, mx);
}

int SortCol(int c, vvi& ret){
    vi S;
    map<int, int> M;
    for(int i = 0; i < n; i++){
        if(!board[i][c]) continue;
        M[board[i][c]]++;
        S.push_back(board[i][c]);
    }
    sort(S.begin(), S.end()); S.erase(unique(S.begin(), S.end()), S.end());
    sort(S.begin(), S.end(), [&](int& a, int& b){
        return M[a] == M[b] ? a < b : M[a] < M[b];
    });
    for(int i = 0,l = 0; i < sz(S); i++,l+=2){
        ret[l][c] = S[i];
        ret[l + 1][c] = M[S[i]];
    }
    return (sz(S) << 1);
}

void C(){
    int mx = 0; vvi ret(101, vi(101));
    for(int i = 0; i < m; i++){
        auto v = SortCol(i, ret);
        mx = max<int>(mx, v);
    }
    for(int i = 0; i < 101; i++) for(int j = 0; j < 101; j++) board[i][j] = ret[i][j];
    n = min<int>(101, mx);
}

void Print(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cout << board[i][j] << " ";
        cout << '\n';
    }
    cout << "\n";
}

void Main(){
    // input
    int r,c,k; cin >> r >> c >> k; --r,--c;
    for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) cin >> board[i][j];
    int ret = 0;
    while(ret <= 100){
        if(board[r][c] == k){
            cout << ret << '\n';
            return;
        }
        if(n >= m) {R(); ret++; }
        else {C(); ret++;}
    }
    cout << -1 << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}