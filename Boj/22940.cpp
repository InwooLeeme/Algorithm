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

using matrix = vector<vector<double>>;

void Sol(){
    int n; cin >> n; int m = n + 1;
    matrix v(n, vector<double>(m));
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >>  v[i][j];
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
        double w = v[i][j], c = v[j][i] / v[i][i];
        for(int k = 0; k < m; k++){
            if(j == i) v[j][k] /= w;
            else v[j][k] -= c * v[i][k];
        }
    }
    for(int i = 0; i < n; i++) cout << v[i].back() << " ";
    cout << '\n';
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Sol();
    return 0;
}