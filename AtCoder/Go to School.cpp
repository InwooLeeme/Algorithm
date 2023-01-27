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

int32_t main(){
    fastio;
    int N; cin >> N;
    vector<int> v(N + 1);
    for(int i = 1,t; i <= N; i++){
        cin >> t;
        v[t] = i;
    }
    for(int i = 1; i <= N; i++) cout << v[i] << ' ';
    return 0;
}