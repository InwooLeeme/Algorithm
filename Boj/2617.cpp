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

int n,m;

void Floyd(vector<vector<int>>& dist){
    for(int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) dist[i][j] = min<int>(dist[i][j], dist[i][k] + dist[k][j]);
}

void Main(){
    cin >> n >> m;
    const int INF = int(2e18);
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF)),dist2(n + 1, vector<int>(n + 1, INF));
    while(m--){
        int a,b; cin >> a >> b;
        dist[b][a] = 1;
        dist2[a][b] = 1;
    }
    Floyd(dist); Floyd(dist2);
    int ret = 0;
    for(int i = 1; i <= n; i++){
        int cnt1 = 0,cnt2 = 0;
        for(int j = 1; j <= n; j++){
            cnt1 += (dist[i][j] != INF ? 1 : 0);
            cnt2 += (dist2[i][j] != INF ? 1 : 0);
        }
        if(cnt1 >= ((n + 1) >> 1)){
            ret++;
        }
        if(cnt2 >= ((n + 1) >> 1)){
            ret++;
        }
    }
    cout << ret << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}