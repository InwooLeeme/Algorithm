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

int32_t main(){
    fastio;
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        vector<pair<int,string>> v(N);
        for(auto& [a, b] : v) cin >> b >> a;
        sort(v.begin(), v.end(), [&](pair<int,string>& a, pair<int,string>& b){
            return a.first > b.first;
        });
        for(int i = 0; i < N; i++) cout << (v[i].second) << (i != N - 1 ? ", ": "\n");        
    }
    return 0;
}