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

int n;
int D[101010][2];
bitset<101010> vist;
vector<int> G[101010];

void Sol(int cur){
    vist[cur] = 1;
    for(auto nxt : G[cur]){
        if(vist[nxt]) continue;
        Sol(nxt);
    }
    D[cur][0] = 0;
    D[cur][1] = 1;
    for(auto nxt : G[cur]){
        D[cur][0] += D[nxt][1];
        D[cur][1] += min<int>(D[nxt][0], D[nxt][1]);
    }
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    cin >> n;
    for(int i = 1; i < n; i++){
        int a,b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    Sol(1);
    cout << min<int>(D[1][0], D[1][1]) << "\n";
    return 0;
}