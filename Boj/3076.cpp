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

string v[111];

void Main(){
    int r,c,a,b; cin >> r >> c >> a >> b;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(~(i + j) & 1) v[i][j] = 'X';
            else v[i][j] = '.';
        }
    }
    for(int i = 0; i < r; i++){
        for(int _ = 0; _ < a; _++){
            for(int j = 0; j < c; j++){
                for(int __ = 0; __ < b; __++){
                    cout << v[i][j];
                }
            }
            cout << "\n";
        }
    }
}   

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}
