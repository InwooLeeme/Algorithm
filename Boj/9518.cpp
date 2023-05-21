# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#define int int_fast64_t

using pt = pair<int, int>;

int n,m;
string board[55];
int v[55][55];
bool Bound(int x, int y) { return x < 0 || x >= n or y < 0 or y >= m; }
const int ddx[8] = {0, 0, 1, 1, 1, -1, -1, -1}, ddy[8] = {1, -1, 1, 0, -1, 1, 0, -1};

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> board[i];
    int t1 = 0,t2 = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 'o'){
                for(int d = 0; d < 8; d++){
                    auto nx = i + ddx[d], ny = j + ddy[d];
                    if(Bound(nx, ny)) continue;
                    if(board[nx][ny] == 'o') t2++;
                    else v[nx][ny]++;
                }
            }
        }
    }
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) t1 = max<int>(t1, v[i][j]);
    cout << (t1 + (t2 >> 1)) << "\n";
    return 0; 
}
