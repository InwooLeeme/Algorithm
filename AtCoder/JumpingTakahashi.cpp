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

#define int int64_t

using pii = pair<int,int>;

int D[101][11111];
/* 
D[j][k] : j번 점프후에 k에 도달할 수 있으면 1 없으면 0
 */

int32_t main(){
    fastio;
    int n,x; cin >> n >> x;
    D[0][0] = 1;
    vector<int> a(n),b(n);
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= x; j++){
            if(D[i][j]){ // 도달 가능한 좌표에 대해서
                if(j + a[i] <= x) D[i + 1][j + a[i]] = 1;
                if(j + b[i] <= x) D[i + 1][j + b[i]] = 1;
            }
        }
    }
    if(D[n][x]) cout << "Yes";
    else cout << "No";
    return 0;
}