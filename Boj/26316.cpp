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

void Sol(){
    int n,d; cin >> n >> d;
    string s; cin >> s;
    queue<int> Q;
    vector<int> dist(n + 1, -1);
    Q.push(0);
    dist[0] = 0;
    while(Q.size()){
        auto cur = Q.front(); Q.pop();
        for(int cost = d + 1; cost >= 1; cost--){
            if(cur + cost < 0 or cur + cost >= n or s[cur + cost] == 'X' or dist[cur + cost] != -1) continue;
            dist[cur + cost] = dist[cur] + 1;
            Q.push(cur + cost);
        }
    }
    cout << n << ' ' << d << "\n" << s << "\n" << (dist[n - 1] == -1 ? 0 : dist[n - 1]) << '\n';
    cout << "\n";
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t;
    for(int tc = 1; tc <= t; tc++){
        cout << "Day #" << tc << "\n";
        Sol();
    }
    return 0;
}