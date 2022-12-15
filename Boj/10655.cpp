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

using pii = pair<int,int>;

pii v[100011];

int D(pii& a,pii& b){
    return (abs(a.first - b.first) + abs(b.second - a.second));
}

int32_t main(){
    fastio;
    int N,mn = 0,tot = 0; cin >> N;
    for(int i = 0; i < N; i++) cin >> v[i].first >> v[i].second;
    for(int i = 1; i < N; i++) tot += D(v[i - 1], v[i]);
    pii cur,prev,nxt;
    for(int i = 1; i < N - 1; i++){
        prev = v[i - 1];
        cur = v[i];
        nxt = v[i + 1];
        int t1 = D(prev, cur) + D(cur, nxt);
        int t2 = D(prev, nxt);
        mn = max<int>(mn, t1 - t2);
    }
    cout << tot - mn << "\n";
    return 0;
}