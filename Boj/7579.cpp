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

int memory[111],cost[111];
int d[11111];

int32_t main(){
    fastio;
    int n,m,sum = 0; cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> memory[i];
    for(int i = 1; i <= n; i++){
        cin >> cost[i];
        sum += cost[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = sum; j >= cost[i]; j--){
            d[j] = max(d[j], d[j - cost[i]] + memory[i]);
        }
    }
    for(int i = 0; i <= sum; i++){
        if(d[i] >= m){
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}