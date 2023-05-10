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

const int MOD = 1000007;

int tx,ty,w,h;
int d[222][222];

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> w >> h >> tx >> ty;
    for(int i = 0; i < h; i++) d[i][0] = 1;
    for(int i = 1; i < w; i++) d[0][i] = 1;
    for(int i = 1; i < h; i++) for(int j = 1; j < w; j++){
        d[i][j] = (d[i - 1][j] + d[i][j - 1]) % MOD;
    }
    cout << (d[ty - 1][tx - 1] * d[h - ty][w - tx]) % MOD << "\n";
    return 0;
}