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

using ll = long long;

const ll INF = ll(1e18);
ll n,A,B,C,D, x[10101];
bitset<10000> vist;

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> A >> B >> C >> D;
    for(ll i = 0; i < n; i++) cin >> x[i];
    auto f = [&](int i, int j) -> ll{
        if(i > j) swap(i, j);
        return (((__int128)x[i] * A + (__int128)x[j] * B) % C) ^ D;
    };
    ll ret = 0;
    vector<ll> dist(n, INF); dist[0] = 0;
    for(ll i = 0; i < n; i++){
        ll cur = 0;
        ll mn = INF;
        for(ll j = 0; j < n; j++){
            if(!vist[j] and mn > dist[j]){
                mn = dist[j];
                cur = j;
            }
        }
        vist[cur] = 1, ret += dist[cur];
        for(ll j = 0; j < n; j++){
            if(vist[j]) continue;
            if(f(cur, j) > dist[j]) continue;
            dist[j] = f(cur, j);
        }
    }
    cout << ret << "\n";
    return 0;
}