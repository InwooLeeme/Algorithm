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

constexpr int sz = 1 << 11;
vector<int> dist(sz + 1, -1);

int b2i(string& s){
    int ret = 0;
    for(auto& i : s) ret = (ret << 1) | (i & 1);
    return ret;
}

int32_t main(){
    fastio;
    string __a,__b; cin >> __a >> __b;
    int a = b2i(__a),b = b2i(__b);
    queue<int> Q;
    dist[a] = 0;
    Q.push(a);
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int i = 0, _nxt = cur; _nxt >> 1; i++,_nxt >>= 1){
            if(int nxt = cur ^ 1 << i; dist[nxt] == -1){
                dist[nxt] = dist[cur] + 1; Q.push(nxt);
            }
        }
        if(cur && dist[cur - 1] == -1){
            dist[cur - 1] = dist[cur] + 1,Q.push(cur - 1);
        }
        if(cur + 1 < sz && dist[cur + 1] == -1){
            dist[cur + 1] = dist[cur] + 1,Q.push(cur + 1);
        }
    }
    cout << dist[b] << "\n";
    return 0;
}