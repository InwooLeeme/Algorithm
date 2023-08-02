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

vector<int> G[300'010];
int color[300'101];
int vist[300'101];

void Init(int n){
    for(int i = 0; i < 300010; i++) G[i].clear();
    fill(vist, vist + 300101, 0);
    fill(color, color + 300101, 0);
}

void Sol(){
    int n,m; cin >> n >> m;
    Init(n);
    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);
    }
    function<void(int, int)> DFS = [&](int cur, int c){
        color[cur] = c;
        vist[cur] = 1;
        for(auto nxt : G[cur]){
            if(vist[nxt]) continue;
            DFS(nxt, 3 - c);
        }
    };
    for(int i = 1; i <= n; i++){
        if(!vist[i]) DFS(i, 1);
    }
    for(int i = 1; i <= n; i++){
        for(auto& j : G[i]){
            if(color[i] == color[j]){
                cout << "NO" << "\n";
                return;
            }
        }
    }
    cout << "YES" << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    int t; cin >> t;
    while(t--) Sol();
    return 0;
}