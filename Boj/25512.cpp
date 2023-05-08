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

using pii = pair<int, int>;

int n;
vector<int> g[111'111];
vector<int> color(111'111);
bitset<111111> vist;

void f(int cur, int c){
    color[cur] = c;
    int revc = 3 - c;
    vist[cur] = 1;
    for(auto nxt : g[cur]){
        if(vist[nxt]) continue;
        f(nxt, revc);
    }
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    vector<pii> plat(n);
    for(int i = 1; i < n; i++){
        int a,b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(auto& [a, b] : plat) cin >> a >> b;
    int ret1 = 0,ret2 = 0;
    for(int i = 0; i < n; i++){
        if(!vist[i]){
            f(i, 1);
        }
    }
    for(int i = 0; i < n; i++){
        if(color[i] == 1) ret1 += plat[i].first;
        else ret1 += plat[i].second;
    }
    fill(color.begin(), color.end(), 0);
    vist.reset();
    for(int i = 0; i < n; i++){
        if(!vist[i]){
            f(i, 2);
        }
    }
    for(int i = 0; i < n; i++){
        if(color[i] == 1) ret2 += plat[i].first;
        else ret2 += plat[i].second;
    }
    cout << min<int>(ret1, ret2) << "\n";
    return 0;
}