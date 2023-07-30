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
const int INF = int(-1e18);

int v[111][111];
int n,tc = 1,mx = INF;

bool Bound(int x, int y){ return x < 0 or x >= n or y < 0 or y >= n; };

int dir[13][4][2] = {
	{{0,0} ,{0,1},{0,2},{0,3}}, 
    {{0,0},{1,0},{2,0},{3,0}}, 
    {{0,0},{0,1},{1,1},{1,2}}, 
    {{0,1},{1,0},{1,1},{2,0}},
    {{0,0},{0,1},{0,2},{1,2}}, 
    {{0,0},{0,1},{1,0},{2,0}},
    {{0,0},{1,0},{1,1},{1,2}},
    {{0,1},{1,1},{2,1},{2,0}},
    {{0,0},{0,1},{1,0},{1,1}}, 
    {{0,0},{1,0},{1,1},{2,0}}, 
    {{0,1},{1,0},{1,1},{2,1}}, 
    {{0,1},{1,0},{1,1},{1,2}}, 
    {{0,0},{0,1},{0,2},{1,1}} 
};

void Get(int x, int y){
    bool check = 1;
    int sum = 0;
    for(int i = 0; i < 13; i++){
        check = 1;
        sum = 0;
        for(int d = 0; d < 4; d++){
            auto nx = x + dir[i][d][0], ny = y + dir[i][d][1];
            if(Bound(nx, ny)){
                check = 0;
                break;
            }
            sum += v[nx][ny];
        }
        if(!check) continue;
        mx = max<int>(mx, sum);
    }
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    while(1){
        cin >> n;
        if(n == 0) break;
        mx = INF;
        memset(v, 0, sizeof v);
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> v[i][j];
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) Get(i, j);
        cout << tc++ << ". " << mx << "\n";
    }
    return 0;
}