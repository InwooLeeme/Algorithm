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
    int n,m; cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int sum = 0;
    for(int i = 1; i < (1 << n); i++){
        int S = 1;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)) S *= v[j];
        }
        if(__builtin_popcount(i) & 1) sum += (m / S);
        else sum -= (m / S);
    }
    cout << sum << "\n";
    return 0;
}