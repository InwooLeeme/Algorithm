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

int n,c,m;
int cp[2222]; 
struct Query{
    int s,t,cost;
};

int32_t main(){
    fastio;
    cin >> n >> c >> m;
    vector<Query> v(m);
    for(auto& [s ,t ,cost] : v) cin >> s >> t >> cost;
    sort(v.begin(), v.end(), [&](const Query& a, const Query& b){
        return (a.t == b.t ? a.s < b.s : a.t < b.t);
    });
    int ret = 0;
    for(auto& [s, e, cost] : v){
        int mx = 0;        
        for(int j = s; j < e; j++) mx = max<int>(mx, cp[j]);
        int val = min<int>(cost, c - mx);
        ret += val;
        for(int j = s; j < e; j++) cp[j] += val;
    }
    cout << ret << "\n";
    return 0;
}