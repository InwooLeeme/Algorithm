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

using matrix = vector<vector<int>>;

int n,m,s,t;

matrix Mul(matrix& a, matrix& b){
    matrix ret(a.size(), vector<int>(b[0].size()));
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            for(int k = 0; k < b[0].size(); k++){
                ret[i][k] = ret[i][k] + a[i][j] * b[j][k];
            }
        }
    }
    return ret;
}

matrix Pow(matrix& x, int n){
    const int sz = x.size();
    matrix ret(sz, vector<int>(sz, 0));
    for(int i = 0;  i < sz; i++) ret[i][i] = 1;
    while(n){
        if(n & 1) ret = Mul(ret, x);
        x = Mul(x, x);
        n >>= 1;
    }
    return ret;
}

int32_t main(){
    fastio;
    cin >> n >> m >> s >> t;
    matrix A(n, vector<int>(n, 0));
    while(m--){
        int a,b; cin >> a >> b;
        A[a][b] = 1;
        A[b][a] = 1;
    }
    auto S = Pow(A, t);
    int ret = 0;
    for(int i = 0; i < n; i++) ret += S[s][i];
    cout << ret << "\n";
    return 0;
}