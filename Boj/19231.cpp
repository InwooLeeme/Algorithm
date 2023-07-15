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

using p = pair<int, int>;

int n,m,k,q;
vector<int> g[111'111];
vector<int> dist(111'111, -1);

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k >> q;
    queue<int> Q;
    while(k--){ int x; cin >> x; dist[x] = 0; Q.push(x);  }
    while(m--){
        int a,b; cin >> a >> b;
        g[a].push_back(b); g[b].push_back(a);
    }
    while(Q.size()){
        auto cur = Q.front(); Q.pop();
        for(auto nxt : g[cur]){
            if(dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1; Q.push(nxt);
        }
    }
    auto f = [&](int x, int k) -> int{
        int ret = 0,sum = 0,cur = k;
        while(sum < x){
            sum += cur;
            cur += k;
            ret++;
        }
        return ret;
    };
    for(int i = 1; i <= n; i++) cout << f(dist[i], q) << ' ';
    return 0;
}