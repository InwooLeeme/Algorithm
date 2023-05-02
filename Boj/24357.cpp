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

int v[3][3],b[3][3];
const int ddx[8] = {0, 0, 1, 1, 1, -1, -1, -1}, ddy[8] = {1, -1, 1, 0, -1, 1, 0, -1};

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) cin >> v[i][j];
    auto Bound = [](int x, int y) -> bool { return x < 0 || x >= 3 || y < 0 || y >= 3; };
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(v[i][j] == 9){
                b[i][j] = 9;
                continue;    
            }        
            for(int d = 0; d < 8; d++){
                auto nx = i + ddx[d], ny = j + ddy[d];
                if(Bound(nx, ny)) continue;
                if(v[nx][ny] == 9) b[i][j]++;
            }
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++) cout << b[i][j] << " ";
        cout << "\n";
    }
    return 0;
}