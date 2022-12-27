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

int Conv(int x){
    string ret = to_string(x);
    reverse(ret.begin(), ret.end());
    return stoi(ret);
}

int Sol(){
    int n; cin >> n;
    vector<int> dist(1'000'001, -1);
    queue<int> Q;
    dist[1] = 1;
    Q.push(1);
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        if(cur == n) break;
        for(auto nxt : {cur + 1, Conv(cur)}){
            if(nxt < 0 || nxt > 1000000 || dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
        }
    }
    return dist[n];
}

int32_t main(){
    fastio;
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++){
        cout << "Case #" << tc << ": " << Sol() << "\n";
    }
    return 0;
}