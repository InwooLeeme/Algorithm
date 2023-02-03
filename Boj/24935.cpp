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

using pii = pair<int ,int>;

bool check[1111][1111];
int dist[1111][1111];
bool vist[1111];
int n,k;

void DFS(int cur){
    vist[cur] = 1;
    for(int i = 0; i < n; i++){
        if(vist[i] || dist[cur][i] == -1) continue;
        check[cur][i] = 1;
        DFS(i);
    }
}

int32_t main(){
    fastio;
    cin >> n >> k;
    memset(dist, -1, sizeof dist);
    for(int i = 1; i < n; i++){
        int a,b,c; cin >> a >> b >> c;
        dist[b][a] = c;
    }
    while(k--){
        int x; cin >> x;
        memset(vist, 0, sizeof vist);
        DFS(x);
    }
    int ret = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(check[i][j]) ret += (dist[i][j] << 1);
        }
    }
    cout << ret << "\n";
    return 0;
}